#include "Led.hpp"
#include <fstream>
#include <ios>
#include <iostream>

Led::Led()
{
    possibleNames.assign({"led","LED","Led"});
}

void Led::run(devices device)
{
   static bool last_status = false;
   std::cout << "led status: " << device.status << std::endl;
   std::ofstream file;
   if(device.status != last_status)
    {
        file.open("/dev/led-Driver");
        if (device.status == 1)
        {
            file.write("1", sizeof(char));
            file.close();
        }
        else 
        {
            file.write("0", sizeof(char));
            file.close();
        }
    }

    last_status = device.status;
}
