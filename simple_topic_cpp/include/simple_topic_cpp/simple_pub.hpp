#ifndef SIMPLE_TOPIC_CPP__SIMPLE_PUB_HPP_
#define SIMPLE_TOPIC_CPP__SIMPLE_PUB_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace simple_topic_cpp
{
class SimplePub : public rclcpp::Node
{
public:
  SimplePub()
  : Node("simple_pub")
  {
    pub_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);

    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(1000),
      std::bind(&SimplePub::timer_callback, this));
  }

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;

  rclcpp::TimerBase::SharedPtr timer_;

  void timer_callback()
  {
    auto msg = std_msgs::msg::String();
    msg.data = "Hello world from Korea!";
    RCLCPP_INFO(this->get_logger(), "Publishing message");
    RCLCPP_INFO(this->get_logger(), "Data: %s", msg.data.c_str());
    pub_->publish(msg);
  }
};
}  // namespace simple_topic_cpp
#endif  // SIMPLE_TOPIC_CPP__SIMPLE_PUB_HPP_
