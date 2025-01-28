# Communicate_Toolkit
为Robomaster25赛季模块Communicate_2025上下位机通信设计的基于QT的调试工具，帮助使用者快速勘误与定位问题

## 依赖

- ROS 2 Humble
- Qt 5
- C++11 或更高版本

## 编译和运行

### 编译

1. 确保已安装 ROS 2 和 Qt 5。
2. 克隆此项目：

    ```bash
    git clone https://github.com/SillyBeee/Communicate_Debug_Toolkit.git
    ```

3. 编译项目：

    ```bash
    cd ~/Communicate_Toolmkit
    source /opt/ros/humble/setup.bash
    colcon build --symlink-install
    source install/setup.bash
    ```

### 运行

1. 运行可执行文件：

    ```bash
    ros2 run visualization_tool visualization_tool_node
    ```

## 使用说明

1. 启动程序后，将会显示一个基于 Qt 的 GUI 界面。
2. 通过订阅 `/shoot_info` 和 `/communicate/debug/autoaim` 话题，实时显示相关信息。



## 许可证

此项目使用 MIT 许可证。详情请参阅 LICENSE 文件。
