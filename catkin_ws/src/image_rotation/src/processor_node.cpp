///
/// @file
/// @brief Implementation of the ProcessorNode class
///

#include "processor_node.h"

ProcessorNode::ProcessorNode(const std::string& topic)
:image_transport_handle_(node_handle_),
 topic_(topic) 
{
    publisher_ = image_transport_handle_.advertise((topic_+"_rotated"),10);
    subscriber_ = image_transport_handle_.subscribe(topic_,10,&ProcessorNode::ImageRotationCallBack,this);
}

void ProcessorNode::ImageRotationCallBack(const sensor_msgs::ImageConstPtr& msg)
{
    const float rotation_angle = 180.0f;
    cv_bridge::CvImagePtr cv_ptr;

    //converts the input_msg to a CVImage for applying OpenCV's rotation algorithm
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    ImageAlgorithm::RotateImage(cv_ptr->image,rotation_angle);

    //converts CVImage to a ros_msg
    publisher_.publish(cv_ptr->toImageMsg());
}
