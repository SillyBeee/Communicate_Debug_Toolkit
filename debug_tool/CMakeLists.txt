cmake_minimum_required(VERSION 3.10)

set(CMAKE_AUTOMOC ON)
# 设置项目名称
project(debug_tool)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(debug_tool main.cpp UI.h widget.cpp)

target_link_libraries(debug_tool Qt5::Core Qt5::Widgets)