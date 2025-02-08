
cmake_minimum_required(VERSION 3.16.3)
project (IoTSmartHome)



add_executable(IoTSmartHome_App main.cpp clientHandler/clientHandler.cpp parser/parser.cpp deviceMAnager/deviceManager.cpp  deviceMAnager/idevice.cpp deviceMAnager/Led.cpp serviceManger/serviceManager.cpp) 
target_include_directories(IoTSmartHome_App PUBLIC clientHandler/ parser/  deviceMAnager/ serviceManager/ nlohmann/)
install(TARRGETS IoTSmartHome_App DEFINITION bin)