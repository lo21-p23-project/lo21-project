cmake_minimum_required(VERSION 3.21)
project(lo21_project)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Subdirectories of the project (see CMakeLists.txt for each of them)
add_subdirectory(src/Model)
add_subdirectory(src/View)
add_subdirectory(src/Controller)
add_subdirectory(src/Constants)

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
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

set(SOURCE
        src/App.cpp
        ${MODEL_SOURCE}
        ${VIEW_SOURCE}
        ${CONTROLLER_SOURCE}
        ${CONSTANTS_SOURCE}
        ${COCOA_SOURCE}
        )

set(HEADER
        ${MODEL_HEADER}
        ${VIEW_HEADER}
        ${CONTROLLER_HEADER}
        ${CONSTANTS_HEADER}
        ${COCOA_HEADER}
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

find_package(date CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE date::date date::date-tz)
