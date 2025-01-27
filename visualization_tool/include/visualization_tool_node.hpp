#include <rclcpp/rclcpp.hpp>
#include <communicate_2025/msg/serial_info.hpp>
#include <communicate_2025/msg/autoaim.hpp>
class visualization_node : public rclcpp::Node{
    public:
        visualization_node();
        void Serial_info_callback(const communicate_2025::msg::SerialInfo::SharedPtr msg);
        void Autoaim_callback(const communicate_2025::msg::Autoaim::SharedPtr msg);
    private:
        rclcpp::Subscription<communicate_2025::msg::SerialInfo>::SharedPtr Serial_info_sub;
        rclcpp::Subscription<communicate_2025::msg::Autoaim>::SharedPtr Autoaim_sub;
}