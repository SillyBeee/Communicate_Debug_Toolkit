#include "visualization_tool_node.hpp"
#include <QApplication>
#include "mainwindow.h"
#include <thread>
#include <std_msgs/msg/char.hpp>
visualization_node::visualization_node():
rclcpp::Node("visualization_node"){
    //TODO:自瞄话题
    Serial_info_sub = this->create_subscription<communicate_2025::msg::SerialInfo>(
        "/shoot_info", rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Serial_info_callback,
        this, std::placeholders::_1 ));

    Autoaim_sub = this->create_subscription<communicate_2025::msg::Autoaim>(
        "/communicate/autoaim",
        rclcpp::SensorDataQoS(), 
        std::bind(&visualization_node::Autoaim_callback, 
        this, std::placeholders::_1 ));
    //TODO:机械臂(工程)话题
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

    //TODO:烧饼&英雄话题
    Chassis_ctl_sub = this->create_subscription<geometry_msgs::msg::Twist>(
        "/cmd_vel",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Chassis_ctl_callback,
        this, std::placeholders::_1 ));

    Interaction_ctl_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/behaviortree/interaction",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Interaction_ctl_callback,
        this, std::placeholders::_1 ));

    Moudle_ctl_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/behaviortree/moudle",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Moudle_ctl_callback,
        this, std::placeholders::_1 ));

    Command_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/command",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Command_callback,
        this, std::placeholders::_1 ));

    Hitted_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/hitted",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Hitted_callback,
        this, std::placeholders::_1 ));

    Shoot_status_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/shootstatus",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::Shoot_status_callback,
        this, std::placeholders::_1 ));
    
    //TODO:比赛信息话题
    robot_position_sub = this->create_subscription<std_msgs::msg::Float32MultiArray>(
        "/communicate/position/robot",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::robot_position_callback,
        this, std::placeholders::_1 ));
    
    exro_robot_position_sub = this->create_subscription<std_msgs::msg::Float32MultiArray>(
        "/communicate/position/exrorobot",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::exro_robot_position_callback,
        this, std::placeholders::_1 ));
    
    enemy_robot_positionp_sub = this->create_subscription<std_msgs::msg::Float32MultiArray>(
        "/communicate/position/enemyrobot",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::enemy_robot_position_callback,
        this, std::placeholders::_1 ));

    enemy_exro_robot_position_sub = this->create_subscription<std_msgs::msg::Float32MultiArray>(
        "/communicate/position/enemyexrorobot",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::enemy_exro_robot_position_callback,
        this, std::placeholders::_1 ));
    
    red_robot_hp_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/hp/redrobot",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::red_robot_hp_callback,
        this, std::placeholders::_1 ));
    
    blue_robot_hp_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/hp/bluerobot",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::blue_robot_hp_callback,
        this, std::placeholders::_1 ));
    
    building_hp_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/hp/Building",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::building_hp_callback,
        this, std::placeholders::_1 ));

    game_info_sub = this->create_subscription<std_msgs::msg::Int32MultiArray>(
        "/communicate/gameinfo",
        rclcpp::SensorDataQoS(),
        std::bind(&visualization_node::game_info_callback,
        this, std::placeholders::_1 ));
    



    Fake_arm_control_pub = this->create_publisher<std_msgs::msg::Float32MultiArray>(
        "/engineer/arm_control", rclcpp::SensorDataQoS());

    Faker_arm_thread = std::thread([this](){
        rclcpp::WallRate loop_rate(0.05);
        while (rclcpp::ok()){
            if (this->w.fake_info_sender_page->publish_flag){
                auto msg = std_msgs::msg::Float32MultiArray();
                msg.data.push_back(this->w.fake_info_sender_page->arm_h0_slider->value()/100.0);
                msg.data.push_back(this->w.fake_info_sender_page->arm_x1_slider->value()/100.0);
                msg.data.push_back(this->w.fake_info_sender_page->arm_q2_slider->value()/100.0);
                msg.data.push_back(this->w.fake_info_sender_page->arm_q3_slider->value()/100.0);
                msg.data.push_back(this->w.fake_info_sender_page->arm_q4_slider->value()/100.0);
                msg.data.push_back(this->w.fake_info_sender_page->arm_q5_slider->value()/100.0);
                msg.data.push_back(this->w.fake_info_sender_page->arm_q6_slider->value()/100.0);
                std::cout<<"publish"<<msg.data[0]<<","
                <<msg.data[1]<<","
                <<msg.data[2]<<","
                <<msg.data[3]<<","
                <<msg.data[4]<<","
                <<msg.data[5]<<","
                <<std::endl;
                Fake_arm_control_pub->publish(msg);
            }
        }
    });
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
    this->w.engineer_page->arm_control_h0_edit->setText(QString::number(msg->data[0]));
    this->w.engineer_page->arm_control_x1_edit->setText(QString::number(msg->data[1]));
    this->w.engineer_page->arm_control_q2_edit->setText(QString::number(msg->data[2]));
    this->w.engineer_page->arm_control_q3_edit->setText(QString::number(msg->data[3]));
    this->w.engineer_page->arm_control_q4_edit->setText(QString::number(msg->data[4]));
    this->w.engineer_page->arm_control_q5_edit->setText(QString::number(msg->data[5]));
    this->w.engineer_page->arm_control_q6_edit->setText(QString::number(msg->data[6]));
}

void visualization_node::Interaction_control_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.engineer_page->interaction_control_type_edit->setText(QString::number(msg->data[0]));
    this->w.engineer_page->interaction_control_content_edit->setText(QString::number(msg->data[1]));
}

void visualization_node::Arm_info_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg ){
    this->w.engineer_page->arm_info_h0_edit->setText(QString::number(msg->data[0]));
    this->w.engineer_page->arm_info_x1_edit->setText(QString::number(msg->data[1]));
    this->w.engineer_page->arm_info_q2_edit->setText(QString::number(msg->data[2]));
    this->w.engineer_page->arm_info_q3_edit->setText(QString::number(msg->data[3]));
    this->w.engineer_page->arm_info_q4_edit->setText(QString::number(msg->data[4]));
    this->w.engineer_page->arm_info_q5_edit->setText(QString::number(msg->data[5]));
    this->w.engineer_page->arm_info_q6_edit->setText(QString::number(msg->data[6]));
}

void visualization_node::Interaction_info_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.engineer_page->interaction_info_type_edit->setText(QString::number(msg->data[0]));
    this->w.engineer_page->interaction_info_content_edit->setText(QString::number(msg->data[1]));
}

//烧饼&英雄数据回调函数
void visualization_node::Chassis_ctl_callback(const geometry_msgs::msg::Twist::SharedPtr msg ){
    this->w.sential_page->Chassis_vx_editor->setText(QString::number(msg->linear.x));
    this->w.sential_page->Chassis_vy_editor->setText(QString::number(msg->linear.y));
}

void visualization_node::Interaction_ctl_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.sential_page->Interaction_type_editor->setText(QString::number(msg->data[0]));
    this->w.sential_page->Interaction_content_editor->setText(QString::number(msg->data[1]));
}

void visualization_node::Moudle_ctl_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.sential_page->moudle_ctl_type_editor->setText(QString::number(msg->data[0]));
    this->w.sential_page->moudle_ctl_content_editor->setText(QString::number(msg->data[1]));
}

void visualization_node::Command_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.sential_page->command_target_x_editor->setText(QString::number(msg->data[0]));
    this->w.sential_page->command_target_y_editor->setText(QString::number(msg->data[1]));
    this->w.sential_page->command_keyboard_editor->setText(QString::number(msg->data[2]));
    this->w.sential_page->command_robot_id_editor->setText(QString::number(msg->data[3]));
}

void visualization_node::Hitted_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.sential_page->hitted_editor->setText(QString::number(msg->data[0]));
}

void visualization_node::Shoot_status_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.sential_page->shoot_status_17_editor->setText(QString::number(msg->data[0]));
    this->w.sential_page->shoot_status_42_editor->setText(QString::number(msg->data[1]));
    this->w.sential_page->shoot_status_heat_editor->setText(QString::number(msg->data[2]));
    this->w.sential_page->shoot_frequency_editor->setText(QString::number(msg->data[3]));
}

//比赛信息回调函数
void visualization_node::game_info_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    if (msg->data[0] != this->is_blue){
        this->is_blue = msg->data[0];
    }
    this->w.game_info_page->enemy_color_editor->setText(QString::number(msg->data[0]));
    this->w.game_info_page->game_progress_editor->setText(QString::number(msg->data[1]));
    this->w.game_info_page->Stage_remain_time_editor->setText(QString::number(msg->data[2]));
    this->w.game_info_page->remaining_gold_coin_editor->setText(QString::number(msg->data[3]));

}

void visualization_node::robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg ){
    if ((is_blue != -1)&& (is_blue == 0)){
        this->w.game_info_page->r3_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->r4_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->r5_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
    else if ((is_blue!= -1)&& (is_blue == 1)){
        this->w.game_info_page->b3_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->b4_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->b5_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
}

void visualization_node::exro_robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg ){
    if ((is_blue != -1)&& (is_blue == 0)){
        this->w.game_info_page->r1_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->r2_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->r7_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
    else if ((is_blue!= -1)&& (is_blue == 1)){
        this->w.game_info_page->b1_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->b2_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->b7_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
}

void visualization_node::enemy_robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg ){
    if ((is_blue != -1)&& (is_blue == 1)){
        this->w.game_info_page->r3_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->r4_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->r5_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
    else if ((is_blue!= -1)&& (is_blue == 0)){
        this->w.game_info_page->b3_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->b4_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->b5_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
}

void visualization_node::enemy_exro_robot_position_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg ){
    if ((is_blue != -1)&& (is_blue == 1)){
        this->w.game_info_page->r1_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->r2_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->r7_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
    else if ((is_blue!= -1)&& (is_blue == 0)){
        this->w.game_info_page->b1_robot_position_editor->
        setText(QString::number(msg->data[0])+","+QString::number(msg->data[1]));
        this->w.game_info_page->b2_robot_position_editor->
        setText(QString::number(msg->data[2])+","+QString::number(msg->data[3]));
        this->w.game_info_page->b7_robot_position_editor->
        setText(QString::number(msg->data[4])+","+QString::number(msg->data[5]));
    }
}

void visualization_node::red_robot_hp_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.game_info_page->r1_robot_hp_bar->setHealth(msg->data[0]);
    this->w.game_info_page->r2_robot_hp_bar->setHealth(msg->data[1]);
    this->w.game_info_page->r3_robot_hp_bar->setHealth(msg->data[2]);
    this->w.game_info_page->r4_robot_hp_bar->setHealth(msg->data[3]);
    this->w.game_info_page->r5_robot_hp_bar->setHealth(msg->data[4]);
    this->w.game_info_page->r7_robot_hp_bar->setHealth(msg->data[5]);
}

void visualization_node::blue_robot_hp_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.game_info_page->b1_robot_hp_bar->setHealth(msg->data[0]);
    this->w.game_info_page->b2_robot_hp_bar->setHealth(msg->data[1]);
    this->w.game_info_page->b3_robot_hp_bar->setHealth(msg->data[2]);
    this->w.game_info_page->b4_robot_hp_bar->setHealth(msg->data[3]);
    this->w.game_info_page->b5_robot_hp_bar->setHealth(msg->data[4]);
    this->w.game_info_page->b7_robot_hp_bar->setHealth(msg->data[5]);
}

void visualization_node::building_hp_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg ){
    this->w.game_info_page->red_outpost_hp_bar->setHealth(msg->data[0]);
    this->w.game_info_page->red_base_hp_bar->setHealth(msg->data[1]);
    this->w.game_info_page->blue_outpost_hp_bar->setHealth(msg->data[2]);    
    this->w.game_info_page->blue_base_hp_bar->setHealth(msg->data[3]);
}

visualization_node::~visualization_node(){
    if (Faker_arm_thread.joinable()) {
            Faker_arm_thread.join();
        }
    //...existing code...
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