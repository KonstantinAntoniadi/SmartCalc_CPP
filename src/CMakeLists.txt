cmake_minimum_required(VERSION 3.5)

project(calc VERSION 0.1 LANGUAGES CXX)
find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Widgets LinguistTools)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



set(icon)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{QT5_DIR}/lib/cmake")

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES calc_en_US.ts)

set(PROJECT_SOURCES
        # icon.icns
        resources/resources.qrc
        resources/icons/icon.png
        resources/icons/icon.ico
        resources/icons/icon.icns
        resources/styles/background.png
        main.cpp
        view/qcustomplot.cpp
        view/qcustomplot.h
        view/credit.cpp
        view/credit.h
        view/credit.ui
        view/calculator.h
        view/calculator.cpp
        view/calculator.ui
        view/mainwindow.cpp
        view/mainwindow.h
        view/mainwindow.ui
        controller/controllercalculator.cc
        controller/controllercalculator.h
        controller/controllercredit.cc
        controller/controllercredit.h
        model/expression.h
        model/expression.cc
        model/credit.cc
        model/credit.h
        ${TS_FILES}
)




if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(calc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET calc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(tcalc SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(calc
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

#target_link_libraries(calc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets  Qt5::PrintSupport)
target_link_libraries(calc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(calc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

set_source_files_properties(resources/icons/icon.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(calc)
endif()


add_compile_options("-Wall -Wextra -Wpedantic -Werror")
