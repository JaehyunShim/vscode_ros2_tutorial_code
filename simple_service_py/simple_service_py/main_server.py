import rclpy

from simple_service_py.simple_server import SimpleServer


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(SimpleServer())
    rclpy.shutdown()

if __name__ == '__main__':
    main()
