///
/// @file
/// @brief Implementation of ROS Image Rotation Subscriber
///

#include <iostream>
#include "image_algorithm.h"
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <ros/ros.h>

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
    image_transport::ImageTransport image_transport_handle(image_subscriber_handle);
    image_transport::Subscriber image_subscriber = image_transport_handle.
                                                  subscribe("/sensors/camera/image_color",1000,ImageRotationCallback);
    ros::spin();
    return 0;
}
