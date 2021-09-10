#ifndef SIMPLE_SERVICE_CPP__SIMPLE_SERVER_HPP_
#define SIMPLE_SERVICE_CPP__SIMPLE_SERVER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"

namespace simple_service_cpp
{
class SimpleServer : public rclcpp::Node
{
public:
  SimpleServer()
  : Node("simple_server")
  {
    using std::placeholders::_1;
    using std::placeholders::_2;
    server_ = this->create_service<std_srvs::srv::SetBool>(
      "robot_switch", std::bind(&SimpleServer::server_callback, this, _1, _2));
  }

private:
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr server_;

  void server_callback(
    const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
    std::shared_ptr<std_srvs::srv::SetBool::Response> response)
  {
    RCLCPP_INFO(this->get_logger(), "Received request");
    RCLCPP_INFO(this->get_logger(), "Onoff: %s", request->data ? "true" : "false");
    response->success = true;
    response->message = request->data ? "Turned on" : "Turned off";
  }
};
}  // namespace simple_service_cpp
#endif  // SIMPLE_SERVICE_CPP__SIMPLE_SERVER_HPP_
