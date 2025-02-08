#include "idevice.hpp"
#include <algorithm>
#include <iostream>

bool idevice::contain(std::string name)
{
    std::transform(name.begin(), name.end(),name.begin(),::tolower);
    if (std::find(possibleNames.begin(),possibleNames.end(),name) == possibleNames.end())
    {
        return false;
    } 
    return true;
}