#ifndef SIMPLE_TOPIC_CPP__SIMPLE_SUB_HPP_
#define SIMPLE_TOPIC_CPP__SIMPLE_SUB_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace simple_topic_cpp
{
class SimpleSub : public rclcpp::Node
{
public:
  SimpleSub()
  : Node("sipmle_sub")
  {
    using std::placeholders::_1;
    sub_ = this->create_subscription<std_msgs::msg::String>(
      "chatter", 10, std::bind(&SimpleSub::sub_callback, this, _1));
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

  void sub_callback(const std_msgs::msg::String::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Received message");
    RCLCPP_INFO(this->get_logger(), "Data: %s", msg->data.c_str());
  }
};
}  // namespace simple_topic_cpp
#endif  // SIMPLE_TOPIC_CPP__SIMPLE_SUB_HPP_
