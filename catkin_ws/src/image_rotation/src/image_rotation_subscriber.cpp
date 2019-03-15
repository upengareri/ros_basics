#include <iostream>
#include <ros/ros.h>
#include "../include/utilities.hpp"


#include <image_transport/image_transport.h>
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"
#include <sensor_msgs/image_encodings.h>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

static const std::string OPENCV_WINDOW = "Image Window";

void ImageRotationCallback(const sensor_msgs::ImageConstPtr& msg)
{
    utilities::helloworld();
    ROS_INFO("%d x %d",msg->width,msg->height);
    cv::namedWindow(OPENCV_WINDOW);
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    

    cv::imshow(OPENCV_WINDOW,cv_ptr->image);

    cv::waitKey(3);
}

int  main(int argc, char* argv[])
{ 
    ros::init(argc, argv, "ImageSubscriberNode");
    ros::NodeHandle image_subscriber_handle; 
    ros::Subscriber image_subscriber = image_subscriber_handle.subscribe("/sensors/camera/image_color",1000,ImageRotationCallback);
    ros::spin();
    return 0;
}