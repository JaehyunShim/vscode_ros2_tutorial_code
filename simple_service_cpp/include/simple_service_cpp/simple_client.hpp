#ifndef SIMPLE_SERVICE_CPP__SIMPLE_CLIENT_HPP_
#define SIMPLE_SERVICE_CPP__SIMPLE_CLIENT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"

namespace simple_service_cpp
{
class SimpleClient : public rclcpp::Node
{
public:
  SimpleClient()
  : Node("simple_client")
  {
    client_ = this->create_client<std_srvs::srv::SetBool>("robot_switch");

    while (!client_->wait_for_service(std::chrono::seconds(1))) {
      if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(), "Interruped while waiting for the server.");
        return;
      }
      RCLCPP_INFO(this->get_logger(), "Server not available, waiting again...");
    }

    using std::placeholders::_1;
    auto request = std::make_shared<std_srvs::srv::SetBool::Request>();
    request->data = false;
    RCLCPP_INFO(this->get_logger(), "Sending request");
    RCLCPP_INFO(this->get_logger(), "Onoff: %s", request->data ? "true" : "false");
    client_->async_send_request(
      request, std::bind(&SimpleClient::client_response_callback, this, _1));
  }

private:
  rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr client_;

  using ServiceResponseFuture = rclcpp::Client<std_srvs::srv::SetBool>::SharedFuture;
  void client_response_callback(ServiceResponseFuture future)
  {
    auto response = future.get();
    RCLCPP_INFO(this->get_logger(), "Received response");
    RCLCPP_INFO(this->get_logger(), "Success: %s", response->success ? "true" : "false");
    RCLCPP_INFO(this->get_logger(), "Message: %s", response->message.c_str());
  }
};
}  // namespace simple_service_cpp
#endif  // SIMPLE_SERVICE_CPP__SIMPLE_CLIENT_HPP_
