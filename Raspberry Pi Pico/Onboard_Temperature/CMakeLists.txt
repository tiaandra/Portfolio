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

project(Onboard_Temperature C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Onboard_Temperature Onboard_Temperature.c )

pico_set_program_name(Onboard_Temperature "Onboard_Temperature")
pico_set_program_version(Onboard_Temperature "0.1")

add_library(LCD_16x2 INTERFACE)
target_include_directories(LCD_16x2 INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources(LCD_16x2 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/LCD_16x2.c)
target_link_libraries(LCD_16x2 INTERFACE pico_stdlib)



# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Onboard_Temperature 0)
pico_enable_stdio_usb(Onboard_Temperature 0)

# Add the standard library to the build
target_link_libraries(Onboard_Temperature
        pico_stdlib
        LCD_16x2
        hardware_adc)

# Add the standard include files to the build
target_include_directories(Onboard_Temperature PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Onboard_Temperature)

