

#include <memory>
#include <vector>
#include "idevice.hpp"


class deviceManager
{
    public:
        void manage(std::vector<devices> dev);
        void addDevice(std::shared_ptr<idevice> devicePtr);
    private:
        std::vector<std::shared_ptr<idevice>> device_list ;
};