#include <iostream>
#include <string>
#include <vector>

#ifndef IDEVIE_HPP 
#define IDEVIE_HPP

struct devices
{
    std::string _id;
    std::string identifier;
    std::string name;
    bool status;
};


class idevice
{
    public:
        virtual void run(devices device) = 0;
        bool contain(std::string name);
    protected:
        std::vector<std::string> possibleNames;
};

#endif
