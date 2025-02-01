#include "visualization_tool_node.hpp"
#include <QApplication>
#include "mainwindow.h"
#include <thread>
#include <std_msgs/msg/char.hpp>
visualization_node::visualization_node():
rclcpp::Node("visualization_node"){
    //自瞄话题
    Serial_info_sub = this->create_subscription<communicate_2025::msg::SerialInfo>(
        "/shoot_info", rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Serial_info_callback,
        this, std::placeholders::_1 ));

    Autoaim_sub = this->create_subscription<communicate_2025::msg::Autoaim>(
        "/communicate/autoaim",
        rclcpp::SensorDataQoS(), 
        std::bind(&visualization_node::Autoaim_callback, 
        this, std::placeholders::_1 ));
    //机械臂(工程)话题
    Arm_control_sub = this->create_subscription<std_msgs::msg::Float32MultiArray>(
        "/engineer/arm_control" , 
        rclcpp::SensorDataQoS(), 
        std::bind(&visualization_node::Arm_control_callback, 
        this, std::placeholders::_1 ));

    Interaction_control_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/engineer/interaction_control",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Interaction_control_callback,
        this, std::placeholders::_1 ));

    Arm_info_sub = this->create_subscription<std_msgs::msg::Float32MultiArray>(
        "/communicate/engineerarm",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Arm_info_callback,
        this, std::placeholders::_1 ));

    Interaction_control_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/engineerinteraction",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Interaction_info_callback,
        this, std::placeholders::_1 ));


}

//自瞄数据回调函数
void visualization_node::Serial_info_callback(const communicate_2025::msg::SerialInfo::SharedPtr msg ){
    RCLCPP_INFO(this->get_logger(), "processing_serial_info");
    this->w.general_page->down_yaw_editor->setText(QString::number(msg->yaw));
    this->w.general_page->down_pitch_editor->setText(QString::number(msg->pitch));
    
    this->w.general_page->down_find_bool_editor->setText([&msg]()->QString{
        QString qstr = QString(QChar(static_cast<unsigned char>(msg->is_find.data)));
        return qstr;
    }());

}

void visualization_node::Autoaim_callback(const communicate_2025::msg::Autoaim::SharedPtr msg ){
    RCLCPP_INFO(this->get_logger(), "processing_autoaim");
    this->w.general_page->up_yaw_editor->setText(QString::number(msg->yaw));
    this->w.general_page->up_pitch_editor->setText(QString::number(msg->pitch));
    
    this->w.general_page->up_enemy_color_editor->setText(QString::number(msg->enemy_team_color));
    this-> w.general_page->up_mode_editor->setText(QString::number(msg->mode));
    this->w.general_page->up_rune_flag_editor->setText(QString::number(msg->rune_flag));
    
}

//机械臂(工程)数据回调函数

void visualization_node::Arm_control_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg ){
    
}


void visualization_node::Interaction_control_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    
}


void visualization_node::Arm_info_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg ){
    
}




void visualization_node::Interaction_info_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    
}


int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    QApplication a(argc, argv);  
    auto node = std::make_shared<visualization_node>();
    node->w.show();  // 在主线程显示 Widget

    // 启动 ROS2 的异步线程
    std::thread ros_thread([node]() {
        rclcpp::spin(node);
    });

    // 主线程运行 Qt 事件循环
    int result = a.exec();

    // 清理
    rclcpp::shutdown();
    ros_thread.join();
    return result;
}