#include <iostream>
#include <string>
#include <vector>
#include "pareser.hpp"
#include "nlohmann/json.hpp"

 std::vector<devices> parser::parse(std::string devicesBody)
 {
    std::vector<devices> deviceslist;
    std::vector<std::string> devices = convertBodyToVector(devicesBody);
    for (auto &device : devices)
    {
        struct devices dev = parseDevice(device);
        deviceslist.push_back(dev);
    }
   
    return deviceslist;
 }


 std::vector<std::string> parser::convertBodyToVector(std::string body)
 {
 
    body.insert(0,"{\"data\":");
   body.append("}");
    std::vector<std::string> devices;
    nlohmann::json jsondata = nlohmann::json::parse(body);
    for(auto& device : jsondata["data"])
    {
        devices.push_back(device.dump());
    }
    return devices;
 }

 devices parser::parseDevice(std::string deviceString)
 {
    devices dev;
    nlohmann::json devdata = nlohmann::json::parse(deviceString);
    dev._id = devdata["_id"];
    dev.identifier = devdata["identifier"];
    dev.name = devdata["name"];
    dev.status = devdata["status"];
    return dev;
 }

