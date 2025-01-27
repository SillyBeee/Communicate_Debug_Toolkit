cmake_minimum_required(VERSION 3.10)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_BUILD_TYPE "Debug")
# 设置项目名称
project(visualization_tool)

include_directories(/opt/ros/humble/include)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

add_executable(debug_tool main.cpp UI.h widget.cpp)
ament_auto_add_executable(${PROJECT_NAME}_node
    DIRECTORY src
)

target_link_libraries(debug_tool Qt5::Core Qt5::Widgets)

ament_auto_package()