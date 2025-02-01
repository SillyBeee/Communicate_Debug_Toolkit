#ifndef VISUALIZATION_TOOL_NODE_HPP
#define VISUALIZATION_TOOL_NODE_HPP

#include "mainwindow.h"
#include <rclcpp/rclcpp.hpp>
#include <communicate_2025/msg/serial_info.hpp>
#include <communicate_2025/msg/autoaim.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>
class visualization_node : public rclcpp::Node{
    public:
        visualization_node();
        void Serial_info_callback(const communicate_2025::msg::SerialInfo::SharedPtr msg );
        void Autoaim_callback(const communicate_2025::msg::Autoaim::SharedPtr msg );
        void Arm_control_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void Interaction_control_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void Arm_info_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void Interaction_info_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        MainWindow w;
    private:

        //自瞄通信话题
        rclcpp::Subscription<communicate_2025::msg::SerialInfo>::SharedPtr Serial_info_sub;
        rclcpp::Subscription<communicate_2025::msg::Autoaim>::SharedPtr Autoaim_sub;
        //机械臂(工程)通信话题
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr Arm_control_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr Interaction_control_sub;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr Arm_info_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr Interaction_info_sub;


};      

#endif // VISUALIZATION_TOOL_NODE_HPP