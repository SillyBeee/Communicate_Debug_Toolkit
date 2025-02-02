cmake_minimum_required(VERSION 3.5)
project(visualization_tool)

# 找到Qt5库
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# 找到ROS 2依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(communicate_2025 REQUIRED)

set(PROJECT_SOURCES
    src/visualization_tool_node.cpp
    src/mainwindow.cpp
    include/visualization_tool_node.hpp
    include/mainwindow.h
    Page/T_BasePage.cpp
    Page/T_BasePage.h
    Page/T_com_general.cpp
    Page/T_com_general.h
    Page/T_About.cpp
    Page/T_About.h
    Page/T_Engineer.h
    Page/T_Engineer.cpp
    Page/T_Sential.h
    Page/T_Sential.cpp
    Page/T_Game_info.h
    Page/T_Game_info.cpp
    Page/health_bar.h
    Page/health_bar.cpp
    
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}_node
    ${PROJECT_SOURCES}
)

include_directories(
    include
    Ela_depend
    Page
)

target_link_libraries(${PROJECT_NAME}_node
    Qt5::Widgets
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/libElaWidgetTools.so
)
# 链接Qt5库
target_link_libraries(${PROJECT_NAME}_node
    Qt5::Widgets
)

# 链接ROS 2依赖
ament_target_dependencies(${PROJECT_NAME}_node
    rclcpp
    std_msgs
    communicate_2025
)

install(TARGETS ${PROJECT_NAME}_node
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()