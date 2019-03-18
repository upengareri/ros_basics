///
/// @file
/// @brief Implementation of image processing algorithm
///

#include "image_algorithm.h"

using namespace cv;

void ImageAlgorithm::RotateImage(Mat &image, double angle)
{
    // get rotation matrix for rotating the image around its center in pixel coordinates
    Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    Mat rotation_matrix = getRotationMatrix2D(center, angle, 1.0);
    // determine bounding rectangle, center not relevant
    Rect2f bounding_box = RotatedRect(Point2f(), image.size(), angle).boundingRect2f();
    // adjust transformation matrix
    rotation_matrix.at<double>(0, 2) += bounding_box.width / 2.0 - image.cols / 2.0;
    rotation_matrix.at<double>(1, 2) += bounding_box.height / 2.0 - image.rows / 2.0;

    warpAffine(image, image, rotation_matrix, bounding_box.size());
}

