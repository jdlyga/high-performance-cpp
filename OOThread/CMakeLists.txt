cmake_minimum_required(VERSION 2.8.9)
project(OOThread)

set (CMAKE_CXX_FLAGS "-pthread")

include_directories(.)

file(GLOB SOURCES "*.cpp")
 
add_executable(OOThread ${SOURCES})
