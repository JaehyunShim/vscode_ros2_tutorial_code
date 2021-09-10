import rclpy
from rclpy.node import Node
from std_srvs.srv import SetBool


class SimpleClient(Node):

    def __init__(self):
        super().__init__('simple_client')

        self.client = self.create_client(SetBool, 'robot_switch')

        while not self.client.wait_for_service(timeout_sec=1.0):
            if not rclpy.ok():
                self.get_logger().error('Interruped while waiting for the server.')
                return
            else:
                self.get_logger().info('Server not available, waiting again...')

        self.request = SetBool.Request()
        self.request.data = False
        self.get_logger().info('Sending request')
        self.get_logger().info('Onoff: %s' % ('true' if self.request.data else 'false'))
        self.future = self.client.call_async(self.request)
        self.future.add_done_callback(self.client_response_callback)

    def client_response_callback(self, future):
        response = self.future.result()
        self.get_logger().info('Received response')
        self.get_logger().info('Success: %s' % ('true' if response.success else 'false'))
        self.get_logger().info('Message: %s' % response.message)
