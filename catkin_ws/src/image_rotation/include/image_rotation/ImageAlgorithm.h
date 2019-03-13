#ifndef IMAGE_ALGORITHM_H
#define IMAGE_ALGORITHM_H

#include <opencv2/opencv.hpp>


class ImageAlgorithm
{
  public:
    ImageAlgorithm()
    {
    }
    static void RotateImage(cv::Mat &image, double angle);

};

#endif