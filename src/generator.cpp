#include <stdio.h>
#include <stdlib.h>
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
    

	ros::init(argc, argv, "talker");

	ros::NodeHandle n1,n2,n3;
	
	ros::Publisher pub2 = n3.advertise<beginner_tutorials::intlist>("chatter2",100);

	ros::Subscriber sub = n2.subscribe("chatter3", 100, arrayCallback);

	while (ros::ok())
	{
		beginner_tutorials::intlist array2;
		//Clear array
		array2.data.clear();
		//for loop, pushing data in the size of the array
		for (int i = 0; i < 10; i++)
		{
			array2.data.push_back(7);
		}
		//Publish array
		pub2.publish(array2);
		//Let the world know
        //cout<<endl<<array[10]<<endl;
		ROS_INFO("published");
		//Do this.

		for(int j = 1; j < 10; j++)
		{
			printf("%d, ", Arr[j]);   // subscribed array
		}
		//------------------------------------------

		
		ros::spinOnce();
		//Added a delay so not to spam
		sleep(0.6);
	}

}
