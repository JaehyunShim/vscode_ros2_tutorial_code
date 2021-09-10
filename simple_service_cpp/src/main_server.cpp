#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "simple_service_cpp/simple_server.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<simple_service_cpp::SimpleServer>());
  rclcpp::shutdown();
  return 0;
}
