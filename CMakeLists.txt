cmake_minimum_required(VERSION 3.1.0)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_library(ODB_PGSQL odb-pgsql REQUIRED)
find_library(ODB odb REQUIRED)
find_library(JSONCPP jsoncpp REQUIRED)

set(TARGET tables)

add_subdirectory(src/Database)

add_executable(${TARGET}
    src/MainWindow/MainWindow.hpp
    src/MainWindow/MainWindow.cpp
    src/MainWindow/Utils.cpp

    src/MainWindow/Person/PersonTab.cpp
    src/MainWindow/Person/AddPersonDialog.cpp
    src/MainWindow/Person/RemovePersonDialog.cpp

    src/MainWindow/Auto/AutoTab.cpp
    src/MainWindow/Auto/AddAutoDialog.cpp
    src/MainWindow/Auto/RemoveAutoDialog.cpp

    src/MainWindow/Route/RouteTab.cpp
    src/MainWindow/Route/AddRouteDialog.cpp
    src/MainWindow/Route/RemoveRouteDialog.cpp

    src/MainWindow/Journal/JournalTab.cpp
    src/MainWindow/Journal/AddJournalRowDialog.cpp
    src/MainWindow/Journal/RemoveJournalRowDialog.cpp

    src/MainWindow/Settings/SettingsDialog.cpp

    src/Settings/Settings.cpp

    src/main.cpp
)

target_include_directories(${TARGET} PRIVATE src)

target_link_libraries(${TARGET} Qt5::Widgets database ${ODB_PGSQL} ${ODB} ${JSONCPP} )