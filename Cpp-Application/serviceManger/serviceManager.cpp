#include "serviceManager.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "../deviceMAnager/Led.hpp"

serviceManager::serviceManager(int port)
{
    client.initialize(port);
    manager.addDevice(std::make_shared<Led>());
}

void serviceManager::run()
{
    std::pair<RESULT, std::string> reqBody = client.requestHandler();
    if(reqBody.first == RESULT::SUCCESS)
    {
        std::vector<devices> devList = parse.parse(reqBody.second);
        manager.manage(devList);
    }
}