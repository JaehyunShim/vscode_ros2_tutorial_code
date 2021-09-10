#ifndef SIMPLE_PARAM_CPP__SIMPLE_PARAM_HPP_
#define SIMPLE_PARAM_CPP__SIMPLE_PARAM_HPP_

#include "rclcpp/rclcpp.hpp"

namespace simple_param_cpp
{
class SimpleParam : public rclcpp::Node
{
public:
  SimpleParam()
  : Node("simple_param")
  {
    this->declare_parameter<std::string>("robot_name", "SimpleBot");
    this->declare_parameter<double>("robot_mass", 1.0);
    this->declare_parameter<int>("robot_number", 3);

    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(1000),
      std::bind(&SimpleParam::timer_callback, this));
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;

  void timer_callback()
  {
    auto robot_name = this->get_parameter("robot_name").get_value<std::string>();
    auto robot_mass = this->get_parameter("robot_mass").get_value<double>();
    auto robot_number = this->get_parameter("robot_number").get_value<int>();

    RCLCPP_INFO(this->get_logger(), "robot_name: %s", robot_name.c_str());
    RCLCPP_INFO(this->get_logger(), "robot_mass: %lf", robot_mass);
    RCLCPP_INFO(this->get_logger(), "robot_number: %d", robot_number);
  }
};
}  // namespace simple_param_cpp
#endif  // SIMPLE_PARAM_CPP__SIMPLE_PARAM_HPP_
