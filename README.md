# ros_basics
This project gives an idea on how to publish and subscribe data.
Specifically a node is created that will read image data from ROS bag and publish it. Another node would subscribe to image data, 
do some preprocessing like rotation and then again publish the preprocessed data.
A visualizer node would subscribe to the data and show the preprocessed image
onto the visualizer tool namely rsviz.
