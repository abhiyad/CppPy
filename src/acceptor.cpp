#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "beginner_tutorials/intlist.h"
#include "ros/ros.h"

#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"

int Arr[10];
void arrayCallback(const beginner_tutorials::intlist::ConstPtr& array)
{
	int i = 0;
	// print all the remaining numbers
	for(std::vector<int>::const_iterator it = array->data.begin(); it != array->data.end(); ++it)
	{
		Arr[i] = *it;
		i++;
	}
	return;
}

int main(int argc, char **argv)
{

	ros::init(argc, argv, "listener");
	ros::NodeHandle n,n2,n3;	
	ros::Subscriber sub = n.subscribe("chatter2", 100, arrayCallback);
	//ros::Publisher pub = n2.advertise<std_msgs::Int32MultiArray>("chatter2", 100);
	ros::Publisher pub2 = n3.advertise<beginner_tutorials::intlist>("chatter3",100);



	while(1)
	{
		ros::spinOnce();

		if(Arr[0]!=0)
		for(int j = 1; j < 10; j++)
		{
			printf("%d, ", Arr[j]);   // subscribed array
		}
		printf("\n");
		//------------------------------------------

		//std_msgs::Int32MultiArray array;
		beginner_tutorials::intlist array2;
		//Clear array
		array2.data.clear();
		//for loop, pushing data in the size of the array
		for (int i = 0; i < 10; i++)
		{
			//array.data.push_back(2);
			array2.data.push_back(3);
		}
		//Publish array
		pub2.publish(array2);


		sleep(0.5);
	}
	printf("\n");
	return 0;
}
