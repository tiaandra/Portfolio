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

project(Sonar_HCSR04 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Sonar_HCSR04 Sonar_HCSR04.c )

add_library(HCSR04 INTERFACE)
target_include_directories(HCSR04 INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources(HCSR04 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/HCSR04.c)
target_link_libraries(HCSR04 INTERFACE pico_stdlib)


pico_set_program_name(Sonar_HCSR04 "Sonar_HCSR04")
pico_set_program_version(Sonar_HCSR04 "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Sonar_HCSR04 0)
pico_enable_stdio_usb(Sonar_HCSR04 1)

# Add the standard library to the build
target_link_libraries(Sonar_HCSR04
        pico_stdlib
        HCSR04)

# Add the standard include files to the build
target_include_directories(Sonar_HCSR04 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Sonar_HCSR04)

