
#include "../clientHandler/clientHandler.hpp"
#include "../parser/pareser.hpp"
#include "../deviceMAnager/deviceManager.hpp"


class serviceManager
{
    public:
        serviceManager(int port);
        void run();
    private:
        clientHandler client;
        parser parse;
        deviceManager manager;
};