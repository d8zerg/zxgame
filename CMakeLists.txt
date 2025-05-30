cmake_minimum_required(VERSION 3.20)

project(zxgame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zxgame   
    src/main.cpp)

include(GNUInstallDirs)
install(TARGETS zxgame
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

find_package(nlohmann_json)
target_link_libraries(zxgame nlohmann_json::nlohmann_json) 

# GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
if (GTest_FOUND)
    message(STATUS "Found GTest: TRUE")
else()
    message(FATAL_ERROR "Found GTest: FALSE")
endif()

add_subdirectory(tests)