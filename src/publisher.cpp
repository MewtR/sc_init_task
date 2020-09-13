#include "ros/ros.h"
#include "std_msgs/String.h"

#include <cstdio>
#include <sstream>

int main(int argc, char** argv)
{
    ros::init(argc,argv, "publisher");
    ros::NodeHandle node;

    ros::Publisher pub = node.advertise<std_msgs::String>("listener", 10); 

    ros::Rate loop_rate(10);

    std::string fortune = "";
    char buffer[100];

    while (ros::ok())
    {
        std_msgs::String msg;

        fortune = "";

        FILE* pipe = popen("fortune", "r");

        if(pipe){
            while(fgets(buffer, sizeof buffer, pipe) != NULL){
                fortune += buffer;
            }
        }else{
            fortune = "Unable to run fortune";
        }

        msg.data = fortune;
        pub.publish(msg);
        ROS_INFO("Published message: %s", fortune.c_str());

        pclose(pipe);
        loop_rate.sleep();
    }

}
