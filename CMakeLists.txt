cmake_minimum_required(VERSION 3.25)
project(lo21_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lo21_project src/App.cpp)
target_link_libraries(lo21_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

