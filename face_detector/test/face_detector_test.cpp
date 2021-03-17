#include "gtest/gtest.h"
#include <face_detector.hpp>

TEST(FaceDetectorTest, EmptyImage) {
    EXPECT_EQ(detect_faces(cv::Mat(), "image").size(), 0);
}

TEST(FaceDetectorTest, OneFaceImage) {
    std::string path = std::string(TEST_IMAGES_PATH) + "1200px-Lenna.png";
    cv::Mat img(cv::imread(path));
    EXPECT_EQ(detect_faces(img, path).size(), 1);
}

TEST(FaceDetectorTest, ZeroFaceImage) {
    std::string path = std::string(TEST_IMAGES_PATH) + "nature.jpeg";
    cv::Mat img(cv::imread(path));
    EXPECT_EQ(detect_faces(img, path).size(), 0);
}

TEST(FaceDetectorTest, ManyFaceImage) {
    std::string path = std::string(TEST_IMAGES_PATH) + "manyface.jpeg";
    cv::Mat img(cv::imread(path));
    EXPECT_EQ(detect_faces(img, path).size(), 5);
}
