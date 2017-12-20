 #!/usr/bin/env python
import rospy
from std_msgs.msg import String

def talker():
    a = IntList()
    a.data = [3250,2682,6832,2296,8865,7796,6955,8236]
    pub=rospy.Publisher('sonar_vals',Int32MultiArray,queue_size = 10)    
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        pub.publish(a)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
