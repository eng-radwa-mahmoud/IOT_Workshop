#include <iostream>
#include <sstream>
#include <unistd.h>
#include <utility>
//#include <sstream>
#include "clientHandler.hpp"

clientHandler::clientHandler(){}

clientHandler::~clientHandler(){}

RESULT clientHandler::initialize(int port)
{
 this->Port = port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cout << "Failed to create socket. errno: " << errno << std::endl;
        return RESULT::FAILED;
        exit(EXIT_FAILURE);
    }
  //  std::cout << "1" << std::endl;

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(this -> Port);
    if (bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
        std::cout << "Failed to bind to port:" << this->Port <<" errno: " << errno << std::endl;
        return RESULT::FAILED;
        exit(EXIT_FAILURE);
    }
  //std::cout << "2" << std::endl;

    if (listen(sockfd, 3) < 0) {
        std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
        return RESULT::FAILED;
        exit(EXIT_FAILURE);
    }
  //    std::cout << "3" << std::endl;
    return RESULT::SUCCESS;
}

std::pair<RESULT, std::string> clientHandler::requestHandler()
{
    auto addrlen = sizeof(sockaddr);
    this -> connection = accept(sockfd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
    if (connection < 0) {
        std::cout << "Failed to grab connection. errno: " << errno << std::endl;
        close(sockfd);
        close(connection);
        return std::make_pair(RESULT::FAILED, "");
        exit(EXIT_FAILURE);

    }
    char buffer[1024] = {0};
    int bytesread = recv(connection, buffer, sizeof(buffer), 0);
    if (bytesread == -1)
    {
         std::cout << "doesn't receive" << errno << std::endl;
        close(sockfd);
        close(connection);
        return std::make_pair(RESULT::FAILED, "");
    }
    
 //     std::cout << "5" << std::endl;
      std::string line;
      std::stringstream httppostrequest(buffer); 
        
    // parsing the headers
    while (getline(httppostrequest, line, '\n')) {
        if (line.empty() || line == "\r") {
        break; // end of headers reached
        }
        if (line.back() == '\r') {
            line.resize(line.size()-1);
        }
    }
    std::string const body(std::istreambuf_iterator<char>{httppostrequest}, {});
    std::cout << body << std::endl;
    close(connection);
    return std::make_pair(RESULT::SUCCESS, body);
 


}