#include "ImageAlgorithm.h"

void ImageAlgorithm::RotateImage(cv::Mat &image, double angle)
{
    // get rotation matrix for rotating the image around its center in pixel coordinates
    cv::Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
    // determine bounding rectangle, center not relevant
    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), image.size(), angle).boundingRect2f();
    // adjust transformation matrix
    rot.at<double>(0, 2) += bbox.width / 2.0 - image.cols / 2.0;
    rot.at<double>(1, 2) += bbox.height / 2.0 - image.rows / 2.0;

    // cv::Mat dst;
    cv::warpAffine(image, image, rot, bbox.size());
}
