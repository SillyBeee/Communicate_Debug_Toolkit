#include <rclcpp/rclcpp.hpp>

class visualization_node : public rclcpp::Node{
    public:
        visualization_node();
        
    private:
        rclcpp::Subscription<communicate_2025::msg::SerialInfo>::SharedPtr Serial_info_sub;
        rclcpp::Subscription<communicate_2025::msg::Autoaim>::SharedPtr Autoaim_sub;
}