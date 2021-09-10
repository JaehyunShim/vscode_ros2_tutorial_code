import rclpy

from simple_topic_py.simple_pub import SimplePub


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(SimplePub())
    rclpy.shutdown()

if __name__ == '__main__':
    main()
