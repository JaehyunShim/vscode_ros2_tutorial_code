import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class SimpleSub(Node):

    def __init__(self):
        super().__init__('simple_sub')

        self.sub = self.create_subscription(
            String, 'chatter', self.sub_callback, 10)

    def sub_callback(self, msg):
        self.get_logger().info('Received message')
        self.get_logger().info('Data: %s' % msg.data)
