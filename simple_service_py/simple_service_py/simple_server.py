import rclpy
from rclpy.node import Node
from std_srvs.srv import SetBool


class SimpleServer(Node):

    def __init__(self):
        super().__init__('simple_server')

        self.server = self.create_service(SetBool, 'robot_switch', self.server_callback)

    def server_callback(self, request, response):
        self.get_logger().info('Received request')
        self.get_logger().info('Onoff: %s' % ('true' if request.data else 'false'))
        response.success = True
        response.message = 'Turned on' if request.data else 'Turned off'
        return response
