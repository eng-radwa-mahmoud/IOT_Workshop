

cmake_minimum_required(VERSION 3.17)
project(IoTSmartHome)



# Add the executable
add_executable(IoTSmartHome_App
    main.cpp
    clientHandler/clientHandler.cpp
    parser/parser.cpp
    deviceMAnager/deviceManager.cpp
    deviceMAnager/idevice.cpp
    deviceMAnager/Led.cpp
    serviceManger/serviceManager.cpp
)

# Add include directories for the project
include_directories(IoTSmartHome_App PUBLIC

    clientHandler/
    parser/
    deviceMAnager/
    serviceManger/
   ../Cpp-Application/

)

# Install the executable
install(TARGETS IoTSmartHome_App DESTINATION bin)
