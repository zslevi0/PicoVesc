cmake_minimum_required(VERSION 3.20)

set(PRJ picovesc)

project(${PRJ} VERSION 1.0.0 DESCRIPTION "VESC UART library for Pico")

include_directories(include)

add_library(${PRJ} STATIC src/PicoVesc.cpp
                          src/buffer.cpp
                          src/crc.cpp)

set_target_properties(${PRJ} PROPERTIES VERSION ${PROJECT_VERSION})