set(VIEW_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MainWidget/MainWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/StackedWidget/StackedWidget.cpp

        # Utils
        ${CMAKE_CURRENT_LIST_DIR}/Utils/WidgetsUtils.cpp

        # Menubar
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/MenuBar.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/EditMenu/EditMenu.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/FileMenu/FileMenu.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/HelpMenu/HelpMenu.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/ViewMenu/ViewMenu.cpp

        # Widgets
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/StackedChildWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/HomeWidget/HomeWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/WorkInProgressWidget/WorkInProgressWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/GameOptionsWidget/GameOptionsWidget.cpp

        PARENT_SCOPE
        )

set(VIEW_HEADER
        ${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.h
        ${CMAKE_CURRENT_LIST_DIR}/MainWidget/MainWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/StackedWidget/StackedWidget.h

        # Constants
        ${CMAKE_CURRENT_LIST_DIR}/Constants/Widgets.h

        # Utils
        ${CMAKE_CURRENT_LIST_DIR}/Utils/WidgetsUtils.h

        # Menubar
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/MenuBar.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/EditMenu/EditMenu.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/FileMenu/FileMenu.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/HelpMenu/HelpMenu.h
        ${CMAKE_CURRENT_LIST_DIR}/MenuBar/Menus/ViewMenu/ViewMenu.h

        # Widgets
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/StackedChildWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/HomeWidget/HomeWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/WorkInProgressWidget/WorkInProgressWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/GameOptionsWidget/GameOptionsWidget.h
        PARENT_SCOPE
        )
