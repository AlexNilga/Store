cmake_minimum_required(VERSION 3.22)
project(Store)

set(CMAKE_CXX_STANDARD 14)

add_executable(Store main.cpp Store/Menu.cpp Store/Menu.h Store/MenuItem.cpp Store/MenuItem.h)
