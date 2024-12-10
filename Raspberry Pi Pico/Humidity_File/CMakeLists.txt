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
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Humidity_File C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Humidity_File Humidity_File.c )

add_library(DHT11 INTERFACE)
target_include_directories(DHT11 INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources(DHT11 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/DHT11.c)
target_link_libraries(DHT11 INTERFACE pico_stdlib)

pico_set_program_name(Humidity_File "Humidity_File")
pico_set_program_version(Humidity_File "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Humidity_File 0)
pico_enable_stdio_usb(Humidity_File 1)

# Add the standard library to the build
target_link_libraries(Humidity_File
        pico_stdlib
        DHT11)

# Add the standard include files to the build
target_include_directories(Humidity_File PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Humidity_File)

