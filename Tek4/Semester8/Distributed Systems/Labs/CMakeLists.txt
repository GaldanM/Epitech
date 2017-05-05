cmake_minimum_required(VERSION 3.2)

project(MPI)

add_executable(MPI DS_Exercise02b.cpp)

# Require MPI for this project:
find_package(MPI REQUIRED)

set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})

include_directories(MPI_INCLUDE_PATH)
target_link_libraries(MPI ${MPI_LIBRARIES})