# Communicate_Toolkit

为Robomaster25赛季模块Communicate_2025上下位机通信设计的基于QT的调试工具,帮助使用者快速勘误与定位问题

```diff
- 由于目前版本存在Qt与Ros2线程冲突的问题,可能出现程序异常崩溃的情况 
- 请谨慎使用
```

## 概览

基于[ElaWidgetTool](https://github.com/Liniyous/ElaWidgetTools)与Qt5制作
目前只支持```Ubuntu22.04```与```Qt5.15.3```(因为只在这里测试过QAQ)

## 支持功能

- 自瞄-云台数据可视化
- 比赛数据可视化
- 烧饼及英雄数据可视化
- 工程机械臂数据可视化
- 自瞄假数据发送器
- 机械臂假数据发送器
- 自瞄方波发送

## 主界面

![主界面示例图](/assets/主界面示例.png)
支持黑白主题切换，丝滑动画，搜索等功能

## 依赖

- ROS2 Humble
- Qt 5.15.3

## 编译和运行

### 编译

1. 确保已安装 ROS 2 和 Qt 5。
2. 克隆此项目与子模块：

    ```bash
    git clone https://github.com/SillyBeee/Communicate_Debug_Toolkit.git
    git submodule update --init --recursive
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

## Q&A

如果出现了图标与字体显示错误的问题，请在项目根目录下执行以下命令:

```bash
cp -r ./visualization_tool/Ela_depend/Font  /usr/share/fonts/truetype
```

或打开项目根目录下的```visualization_tool/Ela_depend/Font```文件夹，安装其字体

## 使用说明

1. 启动程序后，将会显示一个基于 Qt 的 GUI 界面。
2. 通过订阅所有Communicate_2025的话题，并实时更新显示相关信息。

## 许可证

此项目使用 MIT 许可证。详情请参阅 LICENSE 文件。

**如果你在项目使用中遇到了任何疑问或有任何建议，请提出 Issue 或联系作者。**
