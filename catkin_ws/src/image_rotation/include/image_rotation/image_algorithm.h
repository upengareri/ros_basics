///
/// @file
/// @brief Declaration of the ImageAlgorithm class
///

#ifndef IMAGE_ALGORITHM_H
#define IMAGE_ALGORITHM_H

#include <opencv2/opencv.hpp>

class ImageAlgorithm
{
  public:
    ImageAlgorithm() = default;
    static void RotateImage(cv::Mat &image, double angle);
};
#endif // IMAGE_ALGORITHM_H

