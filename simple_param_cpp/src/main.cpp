#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "simple_param_cpp/simple_param.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<simple_param_cpp::SimpleParam>());
  rclcpp::shutdown();
  return 0;
}
