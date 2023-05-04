cmake_minimum_required(VERSION 3.21)
project(lo21_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(USED_QT_LIBS Core Gui Widgets)

set(USED_QT_TARGETS)
foreach(COMPONENT IN LISTS USED_QT_LIBS)
    list(APPEND USED_QT_TARGETS Qt6::${COMPONENT})
endforeach()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${USED_QT_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()


set(SOURCE
        src/App.cpp
        ### Model
        src/Model/Board.cpp
        src/Model/Border.cpp
        src/Model/Card.cpp
        src/Model/CombatMode.cpp
        src/Model/Combo.cpp
        src/Model/Deck.cpp
        src/Model/DiscardDeck.cpp
        src/Model/EliteTroops.cpp
        src/Model/Game.cpp
        src/Model/GameOptions.cpp
        src/Model/Hand.cpp
        src/Model/NormalCard.cpp
        src/Model/NormalDeck.cpp
        src/Model/Player.cpp
        src/Model/Round.cpp
        src/Model/Ruse.cpp
        src/Model/Stone.cpp
        src/Model/TacticCard.cpp
        src/Model/TacticDeck.cpp
        src/Model/Turns.cpp
        src/Model/Wall.cpp

        ### View
        # MainWindow
        src/View/MainWindow/MainWindow.cpp

        # Menubar
        src/View/MenuBar/MenuBar.cpp
        src/View/MenuBar/Menus/EditMenu/EditMenu.cpp
        src/View/MenuBar/Menus/FileMenu/FileMenu.cpp
        src/View/MenuBar/Menus/HelpMenu/HelpMenu.cpp
        src/View/MenuBar/Menus/ViewMenu/ViewMenu.cpp

        # Widgets
        src/View/Widgets/HomeWidget/HomeWidget.cpp
        src/View/Widgets/WorkInProgressWidget/WorkInProgressWidget.cpp
        )

set(HEADER
        src/Constants/Constants.h

        ### Model
        src/Model/Board.h
        src/Model/Border.h
        src/Model/Card.h
        src/Model/CombatMode.h
        src/Model/Combo.h
        src/Model/Deck.h
        src/Model/DiscardDeck.h
        src/Model/EliteTroops.h
        src/Model/Game.h
        src/Model/GameOptions.h
        src/Model/Hand.h
        src/Model/NormalCard.h
        src/Model/NormalDeck.h
        src/Model/Player.h
        src/Model/Round.h
        src/Model/Ruse.h
        src/Model/Stone.h
        src/Model/TacticCard.h
        src/Model/TacticDeck.h
        src/Model/Turns.h
        src/Model/Wall.h

        ### View
        # MainWindow
        src/View/MainWindow/MainWindow.h

        # Menubar
        src/View/MenuBar/MenuBar.h
        src/View/MenuBar/Menus/EditMenu/EditMenu.h
        src/View/MenuBar/Menus/FileMenu/FileMenu.h
        src/View/MenuBar/Menus/HelpMenu/HelpMenu.h
        src/View/MenuBar/Menus/ViewMenu/ViewMenu.h

        # Widgets
        src/View/Widgets/HomeWidget/HomeWidget.h
        src/View/Widgets/WorkInProgressWidget/WorkInProgressWidget.h
        )

if (APPLE)
    ### Bridge
    # Objective-C code
    set(SOURCE ${SOURCE} src/Objective-C/CocoaBridge.mm)
    set(HEADER ${HEADER} src/Objective-C/CocoaBridge.h)
endif (APPLE)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
            MANUAL_FINALIZATION
            ${SOURCE} ${HEADER}
            )
else ()
    add_executable(${PROJECT_NAME}
            ${SOURCE} ${HEADER}
            )
endif ()

foreach(QT_TARGET IN LISTS USED_QT_TARGETS)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_TARGET})
endforeach()

set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
        )

install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif ()

