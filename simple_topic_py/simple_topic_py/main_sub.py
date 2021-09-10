import rclpy

from simple_topic_py.simple_sub import SimpleSub


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(SimpleSub())
    rclpy.shutdown()

if __name__ == '__main__':
    main()
