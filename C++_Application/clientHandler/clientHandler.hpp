#include <string>
#include <utility>
#include <netinet/in.h>

enum class RESULT : char
{
    SUCCESS,
    FAILED,
};

class clientHandler
{
    public:
        clientHandler();
        ~clientHandler();
        RESULT initialize(int port);
        std::pair<RESULT, std::string> requestHandler();
    private:
        int Port;
        sockaddr_in sockaddr;
        int sockfd; 
        int connection;


};