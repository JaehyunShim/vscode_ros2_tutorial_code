import rclpy

from simple_service_py.simple_client import SimpleClient


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(SimpleClient())
    rclpy.shutdown()

if __name__ == '__main__':
    main()
