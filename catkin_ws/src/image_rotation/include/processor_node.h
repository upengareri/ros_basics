///
/// @file
/// @brief Declaration of the ProcessorNode class
/// @author Isaac Newton

#ifndef PROCESSOR_NODE_H
#define PROCESSOR_NODE_H

#include "image_rotation/image_algorithm.h"
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <ros/ros.h>

class ProcessorNode
{
  public:
    ProcessorNode(const std::string& topic, const float&& rotation_angle);
    void ImageRotationCallBack(const sensor_msgs::ImageConstPtr& msg);

  private:
    ros::NodeHandle node_handle_;
    image_transport::ImageTransport image_transport_handle_;
    image_transport::Publisher  publisher_;
    image_transport::Subscriber subscriber_;
    const float rotation_angle_;
};
#endif //PROCESSOR_NODE_H
