#include "visualization_tool_node.hpp"
#include <QApplication>
#include "widget.h"
#include <thread>
visualization_node::visualization_node():
rclcpp::Node("visualization_node"){
    // Serial_info_sub = this->create_subscription<communicate_2025::msg::SerialInfo>(
    //     "Serial_info", 10, std::bind(&visualization_node::Serial_info_callback, this, std::placeholders::_1));
    // Autoaim_sub = this->create_subscription<communicate_2025::msg::Autoaim>(
    //     "Autoaim", 10, std::bind(&visualization_node::Autoaim_callback, this, std::placeholders::_1));

    
}



int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);
    
    
    std::thread QT_GUI_thread([&argc, &argv]{
        QApplication a(argc, argv);
        Widget w;
        w.show();
        a.exec();
    });
    QT_GUI_thread.detach();
    rclcpp::spin(std::make_shared<visualization_node>());
    rclcpp::shutdown();
    return 0;
}