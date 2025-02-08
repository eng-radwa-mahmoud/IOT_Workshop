#include <iostream>
#include "serviceManger/serviceManager.hpp"

int main()
{
    serviceManager manager(2244);
    while (1)
    {
        manager.run();
    }
}