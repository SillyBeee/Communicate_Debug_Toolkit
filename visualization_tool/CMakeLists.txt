cmake_minimum_required(VERSION 3.10)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_BUILD_TYPE "Debug")
# 设置项目名称
project(visualization_tool)

include_directories(/opt/ros/humble/include)
include_directories(${CMAKE_SOURCE_DIR}/include)  # 添加这一行
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_cmake_auto REQUIRED)
find_package(communicate_2025 REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_executable(${PROJECT_NAME}_node
    src/visualization_tool_node.cpp
    src/widget.cpp
)

# 使用 ${PROJECT_NAME}_node 作为目标名称
target_link_libraries(${PROJECT_NAME}_node Qt5::Core Qt5::Widgets rclcpp)
target_link_libraries(${PROJECT_NAME}_node
    ${cpp_typesupport_target}
)
ament_auto_package()