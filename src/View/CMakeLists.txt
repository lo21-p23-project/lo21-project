set(VIEW_SOURCE
        ${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MainWidget/MainWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/StackedWidget/StackedWidget.cpp

        # Utils
        ${CMAKE_CURRENT_LIST_DIR}/Utils/WidgetsUtils.cpp

        # Style
        ${CMAKE_CURRENT_LIST_DIR}/Style/Style.cpp

        # Components
        ${CMAKE_CURRENT_LIST_DIR}/Components/BackButton/BackButton.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/Button/Button.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/SwitchButton/SwitchButton.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/SwitchSelector/SwitchSelector.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/SwitchSelector/ButtonSelector/ButtonSelector.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/TextInput/TextInput.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/CardManager/CardManager.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/DragableCard/DragableCard.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/CardSlot/CardSlot.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/HandWidget/HandWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/BorderWidget/BorderWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/ComboWidget/ComboWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Components/DeckWidget/DeckWidget.cpp

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
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/GameWidget/GameWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/PlayerWidget/PlayerWidget.cpp

        PARENT_SCOPE
        )

set(VIEW_HEADER
        ${CMAKE_CURRENT_LIST_DIR}/MainWindow/MainWindow.h
        ${CMAKE_CURRENT_LIST_DIR}/MainWidget/MainWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/StackedWidget/StackedWidget.h

        # Constants
        ${CMAKE_CURRENT_LIST_DIR}/Constants/WidgetsOptions.h
        ${CMAKE_CURRENT_LIST_DIR}/Constants/CardSlotType.h

        # Utils
        ${CMAKE_CURRENT_LIST_DIR}/Utils/WidgetsUtils.h

        # Style
        ${CMAKE_CURRENT_LIST_DIR}/Style/Style.h

        # Components
        ${CMAKE_CURRENT_LIST_DIR}/Components/BackButton/BackButton.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/Button/Button.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/SwitchButton/SwitchButton.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/SwitchSelector/SwitchSelector.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/SwitchSelector/ButtonSelector/ButtonSelector.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/TextInput/TextInput.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/CardManager/CardManager.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/DragableCard/DragableCard.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/CardSlot/CardSlot.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/HandWidget/HandWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/BorderWidget/BorderWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/ComboWidget/ComboWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Components/DeckWidget/DeckWidget.h

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
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/GameWidget/GameWidget.h
        ${CMAKE_CURRENT_LIST_DIR}/Widgets/PlayerWidget/PlayerWidget.h

        PARENT_SCOPE
        )
