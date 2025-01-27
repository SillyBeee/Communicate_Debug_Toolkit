#include "visualization_tool_node.hpp"
#include <QApplication>
#include "widget.h" 

visualization_node::visualization_node(){
    Serial_info_sub = this->create_subscription<communicate_2025::msg::SerialInfo>(
        "Serial_info", 10, std::bind(&visualization_node::Serial_info_callback, this, std::placeholders::_1));
    Autoaim_sub = this->create_subscription<communicate_2025::msg::Autoaim>(
        "Autoaim", 10, std::bind(&visualization_node::Autoaim_callback, this, std::placeholders::_1));
}