#!/usr/bin/env python

from beginner_tutorials.msg import intlist
import numpy
import rospy
import sys
import serial
from std_msgs.msg import String,Int32,Int32MultiArray,MultiArrayLayout,MultiArrayDimension
from rospy.numpy_msg import numpy_msg
from rospy_tutorials.msg import Floats

arr=[1,2,3,4,5,6,7,8,9,10]

def callback(array):
	for i in range(10):
		arr[i]=array.data[i]
	print 'i got'
	for i in range(10):
		print arr[i],


def main(args):

	rospy.init_node('py2', anonymous=True)
	rospy.Subscriber("chatter2", intlist, callback)
	pub=rospy.Publisher('chatter3',intlist)
	r = rospy.Rate(10)
	while not rospy.is_shutdown():
		a = [2,2,2,2,2,2,2,2,2,2]
		pub.publish(a)
		r.sleep();
	rospy.spin()





if __name__ == '__main__':
    import sys, getopt
    main(sys.argv)