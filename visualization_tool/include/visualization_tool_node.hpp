#ifndef VISUALIZATION_TOOL_NODE_HPP
#define VISUALIZATION_TOOL_NODE_HPP

#include "mainwindow.h"
#include <rclcpp/rclcpp.hpp>
#include <communicate_2025/msg/serial_info.hpp>
#include <communicate_2025/msg/autoaim.hpp>
#include <communicate_2025/msg/command.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <atomic>
#include <thread>
#include <chrono>
class visualization_node : public rclcpp::Node{
    public:
        visualization_node();
        ~visualization_node();
        //自瞄通信回调
        void Serial_info_callback(const communicate_2025::msg::SerialInfo::SharedPtr msg );
        void Autoaim_callback(const communicate_2025::msg::Autoaim::SharedPtr msg );
        //机械臂(工程)通信回调
        void Arm_control_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void Interaction_control_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void Arm_info_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void Interaction_info_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        //烧饼&英雄回调
        void Chassis_ctl_callback(const geometry_msgs::msg::Twist::SharedPtr msg );
        void Interaction_ctl_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void Moudle_ctl_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void Command_callback(const communicate_2025::msg::Command::SharedPtr msg );
        void Hitted_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void Shoot_status_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        //比赛信息回调
        void robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void exro_robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void enemy_robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void enemy_exro_robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg );
        void red_robot_hp_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void blue_robot_hp_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void building_hp_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );
        void game_info_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg );


        
        std::atomic<int> is_blue{-1};

        // std::thread 

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
        //烧饼&英雄话题
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr Chassis_ctl_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr Interaction_ctl_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr Moudle_ctl_sub;
        rclcpp::Subscription<communicate_2025::msg::Command>::SharedPtr Command_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr Hitted_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr Shoot_status_sub;
        //比赛信息话题
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr robot_position_sub;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr exro_robot_position_sub;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr enemy_robot_positionp_sub;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr enemy_exro_robot_position_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr red_robot_hp_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr blue_robot_hp_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr building_hp_sub;
        rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr game_info_sub;
        


        rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr Fake_arm_control_pub;

        std::thread Faker_arm_thread;
};      

#endif // VISUALIZATION_TOOL_NODE_HPP