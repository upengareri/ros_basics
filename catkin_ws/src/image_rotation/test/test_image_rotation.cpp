#include <gtest/gtest.h>
#include "image_rotation/image_algorithm.h"
#include "opencv2/opencv.hpp"


int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(TestFixture, image_rotation)
{
    cv::Mat MatActual = cv::imread("/home/shreekant/Desktop/ros_basics/catkin_ws/src/image_rotation/test/Sourav.png", CV_LOAD_IMAGE_COLOR);
    cv::Mat MatRotated = cv::imread("/home/shreekant/Desktop/ros_basics/catkin_ws/src/image_rotation/test/Souravrotated.png", CV_LOAD_IMAGE_COLOR);

    ImageAlgorithm::RotateImage(MatActual, 180);

    bool result = (cv::countNonZero(MatRotated != MatActual) == 0);

    EXPECT_EQ(result, false);

}


TEST(TestFixture, matrix_rotation)
{
    cv::Mat MatActual = (cv::Mat_<double> (3,4) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3);
    cv::Mat MatRotated = (cv::Mat_<double> (3,4) << 3, 2, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    ImageAlgorithm::RotateImage(MatActual, 180);

    bool result = (cv::countNonZero(MatRotated != MatActual) == 0);

    EXPECT_EQ(result, true);
}
