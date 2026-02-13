import sys
from PySide6.QtWidgets import QApplication, QMainWindow
from PySide6.QtCore import QThread, Signal, QObject
from .turtlebot_move_ui import Ui_Form
from .turtlebot_server import Turtlebot3PatrolServer
from geometry_msgs.msg import Twist
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from std_msgs.msg import String
from rclpy.executors import MultiThreadedExecutor
from std_srvs.srv import Trigger
from turtlebot3_msgs.action import Patrol

class RclpyThread(QThread):
    def __init__(self, node):
        super().__init__()
        self.node = node

    def run(self):
        rclpy.spin(self.node)


class TuttlebotGUI(QMainWindow,Ui_Form):
    def __init__(self,ros_node):
        super().__init__()
        self.setupUi(self)
        self.ros_node = ros_node
        self.ros_node.sig.log_signal.connect(self.add_log)

        self.btn_tri.clicked.connect(self.btn_tri_clicked)
        self.btn_rect.clicked.connect(self.btn_rect_clicked)
        self.btn_penta.clicked.connect(self.btn_penta_clicked)
        self.btn_hexa.clicked.connect(self.btn_hexa_clicked)
        self.btn_star.clicked.connect(self.btn_star_clicked)
        self.btn_stop.clicked.connect(self.btn_stop_clicked)
        self.btn_exit.clicked.connect(self.close)

    def add_log(self,text):
        self.listWidget.addItem(text)
        self.listWidget.scrollToBottom()

    def btn_tri_clicked(self):
        self.listWidget.addItem('삼각형 그리는 중...')
        self.ros_node.send_goal(mode=2, dist=1.5, count=1)
    def btn_rect_clicked(self):
        self.listWidget.addItem('사각형 그리는 중...')
        self.ros_node.send_goal(mode=1, dist=1.5, count=1)
    def btn_penta_clicked(self):
        self.listWidget.addItem('오각형 그리는 중...')
        self.ros_node.send_goal(mode=3, dist=1.0, count=1)
    def btn_hexa_clicked(self):
        self.listWidget.addItem('육각형 그리는 중...')
        self.ros_node.send_goal(mode=4, dist=1.0, count=1)
    def btn_star_clicked(self):
        self.listWidget.addItem('별모양 그리는 중...')
        self.ros_node.send_goal(mode=5, dist=1.5, count=1)
    def btn_stop_clicked(self):
         self.listWidget.addItem('작동을 정지합니다!!!')
         self.ros_node.emergency_stop()

class Signal(QObject):
    log_signal = Signal(str)

class Turtlebot3PatrolClient(Node):
    def __init__(self):
        super().__init__('turtlebot3_patrol_client')
        self.sig = Signal()
        self._action_client = ActionClient(self, Patrol, 'turtlebot3')
        self.stop_client = self.create_client(Trigger, 'emergency_stop')

    def send_goal(self, mode, dist, count):
        goal_msg = Patrol.Goal()
        goal_msg.goal.x = float(mode)
        goal_msg.goal.y = float(dist)
        goal_msg.goal.z = float(count)

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        msg = 'Result: {0}'.format(result.result)
        self.get_logger().info(msg)
        self.sig.log_signal.emit(msg)

    def feedback_callback(self, feedback_msg):
        msg = f"State: {feedback_msg.feedback.state}"
        self.get_logger().info(msg)
        self.sig.log_signal.emit(msg)

    def emergency_stop(self):
        req = Trigger.Request()
        self.stop_client.call_async(req)
        self.get_logger().info('긴급정지 서비스 요청')



def main(args=None):
    rclpy.init(args=args)
    app = QApplication(sys.argv)
    ros_node = Turtlebot3PatrolClient()
    gui = TuttlebotGUI(ros_node)
    gui.show()
    worker = RclpyThread(ros_node)
    worker.start()
    exit_code = app.exec()
    ros_node.destroy_node()
    rclpy.shutdown()
    sys.exit(exit_code)


if __name__ == '__main__':
    main()
