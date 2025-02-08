#include <string>
#include <vector>
#include "../deviceMAnager/idevice.hpp"

class parser
{
    public:
        std::vector<devices> parse(std::string devicesBody);
    private:
        std::vector<std::string> convertBodyToVector(std::string body);
        devices parseDevice(std::string deviceString);
};