cmake_minimum_required(VERSION 3.22)
project(Store)

set(CMAKE_CXX_STANDARD 14)

add_executable(Store main.cpp Store/Menu.cpp Store/Menu.h Store/MenuItem.cpp Store/MenuItem.h Store/Store.cpp Store/Store.h Store/ProductCatalog.cpp Store/ProductCatalog.h Store/ProductOffer.cpp Store/ProductOffer.h Managers/CatalogManager.cpp Managers/CatalogManager.h Managers/OfferManager.cpp Managers/OfferManager.h)
