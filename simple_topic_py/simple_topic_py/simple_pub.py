import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class SimplePub(Node):

    def __init__(self):
        super().__init__('simple_pub')

        self.pub = self.create_publisher(String, 'chatter', 10)

        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello world from Korea'
        self.get_logger().info('Publishing message')
        self.get_logger().info('Data: %s' % msg.data)
        self.pub.publish(msg)
