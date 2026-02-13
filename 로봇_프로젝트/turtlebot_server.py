import math
import threading
import time

from geometry_msgs.msg import Point
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import rclpy
from rclpy.action import ActionServer
from rclpy.action import GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_srvs.srv import Trigger
from turtlebot3_msgs.action import Patrol


class Turtlebot3PatrolServer(Node):

    def __init__(self):
        super().__init__('turtlebot3_patrol_server')

        print('TurtleBot3 Patrol Server')
        print('----------------------------------------------')

        self._action_server = ActionServer(
            self,
            Patrol,
            'turtlebot3',
            self.execute_callback,
            callback_group=ReentrantCallbackGroup(),
            goal_callback=self.goal_callback)
        self.srv = self.create_service(Trigger, 'emergency_stop', self.emergency_stop_callback)
        self.is_emergency_stop = False

        self.goal_msg = Patrol.Goal()
        self.twist = Twist()
        self.odom = Odometry()
        self.position = Point()
        self.rotation = 0.0

        self.linear_x = 1.0
        self.angular_z = 4.0

        qos = QoSProfile(depth=10)

        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', qos)

        self.odom_sub = self.create_subscription(
            Odometry, 'odom', self.odom_callback, qos
        )

    def init_twist(self):
        self.twist.linear.x = 0.0
        self.twist.angular.z = 0.0
        self.cmd_vel_pub.publish(self.twist)

    def odom_callback(self, msg):
        self.odom = msg

    def get_yaw(self):
        q = self.odom.pose.pose.orientation
        siny = 2.0 * (q.w * q.z + q.x * q.y)
        cosy = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        return math.atan2(siny, cosy)

    def emergency_stop_callback(self, request, response):
        self.get_logger().warn('emergency stop!!!')
        self.is_emergency_stop = True
        self.init_twist()
        response.success = True
        response.message = "로봇이 긴급정지 되었습니다."
        return response

    def go_front(self, position, length):
        start_x = self.odom.pose.pose.position.x
        start_y = self.odom.pose.pose.position.y
        while rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.01)
            if self.is_emergency_stop:
                break
            current_x = self.odom.pose.pose.position.x
            current_y = self.odom.pose.pose.position.y

            diff_distance = math.sqrt(pow(current_x - start_x, 2) + pow(current_y - start_y, 2))
            if diff_distance >= length:
                break
            self.twist.linear.x = self.linear_x
            self.twist.angular.z = 0.0
            self.cmd_vel_pub.publish(self.twist)
            time.sleep(0.05)
        self.init_twist()

    def turn(self, target_angle):
        initial_yaw = self.get_yaw()
        target_yaw = initial_yaw + (target_angle * math.pi / 180.0)

        while rclpy.ok():
            if self.is_emergency_stop:
                break
            rclpy.spin_once(self, timeout_sec=0.1)

            current_yaw = self.get_yaw()
            yaw_diff = abs(
                math.atan2(
                    math.sin(target_yaw - current_yaw),
                    math.cos(target_yaw - current_yaw)
                )
            )

            if yaw_diff < 0.01:
                break

            self.twist.linear.x = 0.0
            self.twist.angular.z = self.angular_z
            self.cmd_vel_pub.publish(self.twist)
            time.sleep(0.01)
        self.init_twist()

    def goal_callback(self, goal_request):
        self.goal_msg = goal_request

        return GoalResponse.ACCEPT

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        self.is_emergency_stop = False
        feedback_msg = Patrol.Feedback()

        length = self.goal_msg.goal.y
        iteration = int(self.goal_msg.goal.z)

        if goal_handle.is_cancel_requested:
            self.init_twist()
            goal_handle.canceled()
            self.get_logger().info('goal cnaceled!')
            return Patrol.Result(result = 'cnaceled by user')
        if self.goal_msg.goal.x == 1:
            for count in range(iteration):
                self.square(feedback_msg, goal_handle, length)
            feedback_msg.state = 'square patrol complete!!'

        elif self.goal_msg.goal.x == 2:
            for count in range(iteration):
                self.triangle(feedback_msg, goal_handle, length)
            feedback_msg.state = 'triangle patrol complete!!'

        elif self.goal_msg.goal.x == 3:
            for count in range(iteration):
                self.pentagon(feedback_msg, goal_handle, length)
            feedback_msg.state = 'pentagon patrol complete!!'

        elif self.goal_msg.goal.x == 4:
            for count in range(iteration):
                self.hexagon(feedback_msg, goal_handle, length)
            feedback_msg.state = 'hexagon patrol complete!!'

        elif self.goal_msg.goal.x == 5:
            for count in range(iteration):
                self.star(feedback_msg, goal_handle, length)
            feedback_msg.state = 'star patrol complete!!'

        if self.is_emergency_stop:
            self.get_logger().error('Patrol Stoped!!!')
            result.result = "긴급정지 되었습니다!!!"
            goal_handle.about()
        else:
            goal_handle.succeed()
            result = Patrol.Result()
            result.result = feedback_msg.state
            self.get_logger().info('Patrol complete.')

        self.init_twist()
        return result

    def square(self, feedback_msg, goal_handle, length):
        self.linear_x = 0.2
        self.angular_z = 13 * (90.0 / 180.0) * math.pi / 100.0

        for i in range(4):
            if self.is_emergency_stop:
                break
            self.position.x = 0.0
            self.angle = 0.0

            self.go_front(self.position.x, length)
            if self.is_emergency_stop:
                break
            self.turn(90.0)
            if self.is_emergency_stop:
                break

            feedback_msg.state = 'line ' + str(i + 1)
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(0.1)

        self.init_twist()

    def triangle(self, feedback_msg, goal_handle, length):
        self.linear_x = 0.2
        self.angular_z = 8 * (120.0 / 180.0) * math.pi / 100.0

        for i in range(3):
            if self.is_emergency_stop:
                break
            self.position.x = 0.0
            self.angle = 0.0

            self.go_front(self.position.x, length)
            if self.is_emergency_stop:
                break
            self.turn(120.0)
            if self.is_emergency_stop:
                break

            feedback_msg.state = 'line ' + str(i + 1)
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(0.5)

        self.init_twist()

    def pentagon(self, feedback_msg, goal_handle, length):
        self.linear_x = 0.2
        self.angular_z = 10 * (72.0 / 180.0) * math.pi / 100.0

        for i in range(5):
            if self.is_emergency_stop:
                break
            self.position.x = 0.0
            self.angle = 0.0

            self.go_front(self.position.x, length)
            if self.is_emergency_stop:
                break
            self.turn(72.0)
            if self.is_emergency_stop:
                break

            feedback_msg.state = 'line ' + str(i + 1)
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(0.5)

        self.init_twist()

    def hexagon(self, feedback_msg, goal_handle, length):
        self.linear_x = 0.2
        self.angular_z = 12 * (60.0 / 180.0) * math.pi / 100.0

        for i in range(6):
            if self.is_emergency_stop:
                break
            self.position.x = 0.0
            self.angle = 0.0

            self.go_front(self.position.x, length)
            if self.is_emergency_stop:
                break
            self.turn(60.0)
            if self.is_emergency_stop:
                break

            feedback_msg.state = 'line ' + str(i + 1)
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(0.5)

        self.init_twist()

    def star(self, feedback_msg, goal_handle, length):
        self.linear_x = 0.2
        self.angular_z = 12 * (144.0 / 180.0) * math.pi / 100.0

        for i in range(5):
            if self.is_emergency_stop:
                break
            self.position.x = 0.0
            self.angle = 0.0

            self.go_front(self.position.x, length)
            if self.is_emergency_stop:
                break
            self.turn(144.0)
            if self.is_emergency_stop:
                break

            feedback_msg.state = 'line ' + str(i + 1)
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(0.5)

        self.init_twist()

def main(args=None):
    rclpy.init(args=args)

    turtlebot3_patrol_server = Turtlebot3PatrolServer()

    rclpy.spin(turtlebot3_patrol_server)


if __name__ == '__main__':
    main()
