
#include "idevice.hpp"
#include <vector>

class Led : public idevice
{
    public:
        Led();
        void run(devices device) override;
        
};