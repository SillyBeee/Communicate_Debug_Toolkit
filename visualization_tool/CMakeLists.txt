cmake_minimum_required(VERSION 3.10)
project(visualization_tool)

# 设置C++标准和其他编译选项
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_AUTOMOC ON)

include_directories(
    include
    ${Qt5Widgets_INCLUDE_DIRS}
)

# 查找ROS 2和Qt依赖
find_package(ament_cmake_auto REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# 自动解析package.xml中的依赖
ament_auto_find_build_dependencies()

# 添加可执行文件并链接依赖
ament_auto_add_executable(${PROJECT_NAME}_node
    src/visualization_tool_node.cpp
    src/widget.cpp
    include/widget.h  # 根据实际路径调整
)


# 正确传递ROS 2依赖
ament_target_dependencies(${PROJECT_NAME}_node
  rclcpp
  std_msgs
  communicate_2025
)

# 手动链接Qt库（非ROS依赖）
target_link_libraries(${PROJECT_NAME}_node
  Qt5::Core
  Qt5::Widgets
)

install(TARGETS ${PROJECT_NAME}_node
    DESTINATION lib/${PROJECT_NAME}
)
# 必须调用ament_package()结尾
ament_package()