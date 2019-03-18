///
/// @file
/// @brief Implementation of ROS Publisher
///

#include <iostream>

#include "../include/image_rotation/image_algorithm.h"

#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <image_transport/image_transport.h>
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include "sensor_msgs/Image.h"

sensor_msgs::ImageConstPtr msg_image;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ImagePublisherNode");
    ros::NodeHandle image_publisher_handler; 
    image_transport::ImageTransport image_transport(image_publisher_handler);

    //Bag 
    rosbag::Bag bag;
    bag.open("/home/melisa/Documents/workspace/ros_basics/catkin_ws/src/image_rotation/new.bag",rosbag::bagmode::Read); 
    rosbag::View view(bag, rosbag::TopicQuery("/sensors/camera/image_color"));

    while (image_publisher_handler.ok()) 
    {
    for(rosbag::MessageInstance const m: rosbag::View(bag))
    {
    msg_image = m.instantiate<sensor_msgs::Image>();
    image_transport::Publisher publisher = image_transport.advertise("/sensors/camera/image_color", 1);
    publisher.publish(msg_image);
    ros::Rate loop_rate(5); 
    loop_rate.sleep();
    }
    ros::spinOnce();
    }
    bag.close();
    return 0;
}