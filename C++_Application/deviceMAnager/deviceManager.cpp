#include "deviceManager.hpp"

void deviceManager::manage(std::vector<devices> dev)
{
    for (auto device : dev) 
    {
        for(auto dbDevice : device_list)
        {
         
            if (dbDevice->contain(device.name))
            {
                dbDevice->run(device);
            }
        }
    }
}
void deviceManager::addDevice(std::shared_ptr<idevice> devicePtr)
{
    device_list.push_back(devicePtr);
}