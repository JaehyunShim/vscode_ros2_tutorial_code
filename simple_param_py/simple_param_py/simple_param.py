import rclpy
from rclpy.node import Node


class SimpleParam(Node):

    def __init__(self):
        super().__init__('simple_param')

        self.declare_parameter('robot_name', 'SimpleBot')
        self.declare_parameter('robot_mass', 1.0)
        self.declare_parameter('robot_number', 3)

        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        self.robot_name = self.get_parameter('robot_name').get_parameter_value().string_value
        self.robot_mass = self.get_parameter('robot_mass').get_parameter_value().double_value
        self.robot_number = self.get_parameter('robot_number').get_parameter_value().integer_value

        self.get_logger().info('robot_name: %s' % self.robot_name)
        self.get_logger().info('robot_mass: %lf' % self.robot_mass)
        self.get_logger().info('robot_number: %d' % self.robot_number)
