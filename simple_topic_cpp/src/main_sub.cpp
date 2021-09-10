#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "simple_topic_cpp/simple_sub.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<simple_topic_cpp::SimpleSub>());
  rclcpp::shutdown();
  return 0;
}
