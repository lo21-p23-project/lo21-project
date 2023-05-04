set(VIEW_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.cpp

        # Menubar
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/MenuBar.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/EditMenu/EditMenu.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/FileMenu/FileMenu.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/HelpMenu/HelpMenu.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/ViewMenu/ViewMenu.cpp

        ${CMAKE_CURRENT_LIST_DIR}/Widgets/HomeWidget/HomeWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/WorkInProgressWidget/WorkInProgressWidget.cpp

        PARENT_SCOPE
        )

set(VIEW_HEADER
        ### View
        # MainWindow
        ${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.h

        # Menubar
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/MenuBar.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/EditMenu/EditMenu.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/FileMenu/FileMenu.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/HelpMenu/HelpMenu.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/ViewMenu/ViewMenu.h

        # Widgets
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/HomeWidget/HomeWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/WorkInProgressWidget/WorkInProgressWidget.h
        PARENT_SCOPE
        )
