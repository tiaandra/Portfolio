# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Temperature_Sensor C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Temperature_Sensor Temperature_Sensor.c )

add_library(LCD_16x2 INTERFACE)
target_include_directories(LCD_16x2 INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources(LCD_16x2 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/LCD_16x2.c)
target_link_libraries(LCD_16x2 INTERFACE pico_stdlib)

add_library(DS18B20 INTERFACE)
target_include_directories(DS18B20 INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources(DS18B20 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/DS18B20.c)
target_link_libraries(DS18B20 INTERFACE pico_stdlib)

pico_set_program_name(Temperature_Sensor "Temperature_Sensor")
pico_set_program_version(Temperature_Sensor "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Temperature_Sensor 0)
pico_enable_stdio_usb(Temperature_Sensor 0)

# Add the standard library to the build
target_link_libraries(Temperature_Sensor
        pico_stdlib
        LCD_16x2
        DS18B20)

# Add the standard include files to the build
target_include_directories(Temperature_Sensor PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Temperature_Sensor)

