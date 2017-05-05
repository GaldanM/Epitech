cmake_minimum_required (VERSION 2.6)
project (SpiderKeylogger)
SET(CMAKE_CXX_FLAGS "-std=c++0x")

include_directories("includes")
include_directories("src")

add_executable(SpiderKeylogger src/main.cpp)