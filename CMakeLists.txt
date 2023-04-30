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

add_executable(lo21_project
        src/App.cpp

        ### Constants
        src/Constants/Constants.h

        ### Views
        # MainWindow
        src/View/MainWindow/MainWindow.cpp
        src/View/MainWindow/MainWindow.h
        src/View/MainWindow/MainWindow.ui

        # Menubar
        src/View/MenuBar/MenuBar.cpp
        src/View/MenuBar/MenuBar.h
        src/View/MenuBar/MenuBar.ui
        src/View/MenuBar/Menus/EditMenu/EditMenu.cpp
        src/View/MenuBar/Menus/EditMenu/EditMenu.h
        src/View/MenuBar/Menus/EditMenu/EditMenu.ui
        src/View/MenuBar/Menus/FileMenu/FileMenu.cpp
        src/View/MenuBar/Menus/FileMenu/FileMenu.h
        src/View/MenuBar/Menus/FileMenu/FileMenu.ui
        src/View/MenuBar/Menus/HelpMenu/HelpMenu.cpp
        src/View/MenuBar/Menus/HelpMenu/HelpMenu.h
        src/View/MenuBar/Menus/HelpMenu/HelpMenu.ui
        src/View/MenuBar/Menus/ViewMenu/ViewMenu.cpp
        src/View/MenuBar/Menus/ViewMenu/ViewMenu.h
        src/View/MenuBar/Menus/ViewMenu/ViewMenu.ui

        # Widgets
        src/View/Widgets/HomeWidget/HomeWidget.cpp
        src/View/Widgets/HomeWidget/HomeWidget.h
        src/View/Widgets/HomeWidget/HomeWidget.ui
        src/View/Widgets/WorkInProgressWidget/WorkInProgressWidget.cpp
        src/View/Widgets/WorkInProgressWidget/WorkInProgressWidget.h
        src/View/Widgets/WorkInProgressWidget/WorkInProgressWidget.ui

        ### Bridge
        # Objective-C code
        src/Objective-C/CocoaBridge.mm
        src/Objective-C/CocoaBridge.h
        )
target_link_libraries(lo21_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

