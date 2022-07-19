cmake_minimum_required(VERSION 3.22)
project(src/Store)

set(CMAKE_CXX_STANDARD 14)

add_executable(Store
        src/main.cpp
        src/SQLite/sqlite3.h
        src/SQLite/sqlite3.c
        src/Repository/Repository.h
        src/Repository/Repository.cpp
        src/Menu/Menu.h
        src/Menu/Menu.cpp
        src/Menu/MenuItem.h
        src/Menu/MenuItem.cpp
        src/Managers/StoreManager.h
        src/Managers/StoreManager.cpp
        src/Store/ProductCatalog.h
        src/Store/ProductOffer.h
        src/Managers/CatalogManager.h
        src/Managers/CatalogManager.cpp
        src/Managers/ReportManager.cpp
        src/Managers/ReportManager.h)
