///
/// @file
/// @brief Implementation of ROS Publisher
///

#include "image_rotation/image_algorithm.h"

#include <image_transport/image_transport.h>
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "ImagePublisherNode");
    ros::NodeHandle image_publisher_handler; 
    image_transport::ImageTransport image_transport(image_publisher_handler);
    sensor_msgs::ImageConstPtr msg_image;

    //Bag 
    rosbag::Bag bag;
    bag.open("new.bag",rosbag::bagmode::Read);
    rosbag::View view(bag, rosbag::TopicQuery("/sensors/camera/image_color"));

    while (image_publisher_handler.ok()) 
    {
      for(rosbag::MessageInstance const message: rosbag::View(bag,rosbag::TopicQuery("/sensors/camera/image_color")))
      {
        msg_image = message.instantiate<sensor_msgs::Image>();
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
