///
/// @file
/// @brief Implementation of ROS Image Rotation Subscriber
///

#include "processor_node.h"

int  main(int argc, char* argv[])
{ 
    ros::init(argc, argv, "ImageSubscriberNode");
    ProcessorNode processor_node ("/sensors/camera/image_color");
    ros::spin();
    return 0;
}
