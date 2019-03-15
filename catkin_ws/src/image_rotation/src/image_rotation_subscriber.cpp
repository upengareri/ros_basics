///
/// @file
/// @brief Implementation of ROS Image Rotation Subscriber
///

#include <iostream>

#include "../include/image_rotation/image_algorithm.h"

#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <image_transport/image_transport.h>
#include <ros/ros.h>
#include "sensor_msgs/Image.h"
#include <sensor_msgs/image_encodings.h>
#include "std_msgs/String.h"

static const std::string OPENCV_WINDOW = "Image Window";

void ImageRotationCallback(const sensor_msgs::ImageConstPtr& msg)
{
    const float rotation_angle = 180.0f;
    cv::namedWindow(OPENCV_WINDOW);
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    ImageAlgorithm::RotateImage(cv_ptr->image,rotation_angle);
    cv::imshow(OPENCV_WINDOW, cv_ptr->image);
    cv::waitKey(3);
}

int  main(int argc, char* argv[])
{ 
    ros::init(argc, argv, "ImageSubscriberNode");
    ros::NodeHandle image_subscriber_handle; 
    ros::Subscriber image_subscriber = image_subscriber_handle.
                                                  subscribe("/sensors/camera/image_color",1000,ImageRotationCallback);
    ros::spin();
    return 0;
}
