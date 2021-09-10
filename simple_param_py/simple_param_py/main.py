import rclpy

from simple_param_py.simple_param import SimpleParam


def main(args=None):
    rclpy.init(args=args)
    rclpy.spin(SimpleParam())
    rclpy.shutdown()

if __name__ == '__main__':
    main()
