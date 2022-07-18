cmake_minimum_required(VERSION 3.22)
project(Store)

set(CMAKE_CXX_STANDARD 14)

add_executable(Store main.cpp
        SQLite/sqlite3.h SQLite/sqlite3.c
        Store/Menu.h Store/Menu.cpp
        Store/MenuItem.h Store/MenuItem.cpp
        Store/Store.h Store/Store.cpp
        Store/Repository.h Store/Repository.cpp)
