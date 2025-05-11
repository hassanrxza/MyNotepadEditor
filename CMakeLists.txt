cmake_minimum_required(VERSION 3.6)
project(MyNotepadEditor)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC On)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core    CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui     CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)

add_executable(MyNotepadEditor
    resources/demo_resources.qrc
    src/main.cpp
    src/MainWindow.cpp
    src/QCodeEditor.cpp
    include/QCodeEditor
    include/MainWindow.hpp
)

target_include_directories(MyNotepadEditor PUBLIC
    include
)

target_link_libraries(MyNotepadEditor
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    Qt5::Network
    ${CMAKE_SOURCE_DIR}/lib/libMyNotepadEditor.a
)
