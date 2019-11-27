cmake_minimum_required(VERSION 3.14)
project(Playground)

set(CMAKE_CXX_STANDARD 17)

add_executable(Playground main.cpp Node.cpp Node.h Graph.cpp Graph.h GraphMatrix.cpp GraphMatrix.h Edge.cpp Edge.h)