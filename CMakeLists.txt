cmake_minimum_required(VERSION 3.1.0)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(TARGET tables)

execute_process(COMMAND ./generateUI.sh)

add_executable(${TARGET}
    src/main.cpp
    src/MainWindow/MainWindow.hpp
    src/MainWindow/MainWindow.cpp
    src/MainWindow/Tabs/PersonTab.cpp
    src/Database/DbApi.cpp
    src/Database/Person.cpp
)

target_include_directories(${TARGET} PRIVATE src)

target_link_libraries(${TARGET} Qt5::Widgets)