#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "simple_topic_cpp/simple_pub.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<simple_topic_cpp::SimplePub>());
  rclcpp::shutdown();
  return 0;
}
