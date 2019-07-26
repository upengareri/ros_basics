///
/// @file
/// @brief Implementation of image processing algorithm
///

#include "image_rotation/image_algorithm.h"

using namespace cv;

void ImageAlgorithm::RotateImage(Mat &image, double angle)
{
    
    Rect2f bounding_box = RotatedRect(Point2f(), image.size(), angle).boundingRect2f();
    // adjust transformation matrix
    rotation_matrix.at<double>(0, 2) += bounding_box.width / 2.0 - image.cols / 2.0;
    rotation_matrix.at<double>(1, 2) += bounding_box.height / 2.0 - image.rows / 2.0;

    Rect2f bounding_box = RotatedRect(Point2f(), image.size(), angle).boundingRect2f();
    // adjust transformation matrix
    rotation_matrix.at<double>(0, 2) += bounding_box.width / 2.0 - image.cols / 2.0;
    rotation_matrix.at<double>(1, 2) += bounding_box.height / 2.0 - image.rows / 2.0;


    warpAffine(image, image, rotation_matrix, bounding_box.size());
}

