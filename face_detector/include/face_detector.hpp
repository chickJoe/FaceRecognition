#pragma once

#include <opencv2/opencv.hpp>
#include "config.h"

cv::CascadeClassifier _cv_detector = cv::CascadeClassifier(CASCADE_PATH);

// Detects faces in image and return coordinates of their rectangles 
std::vector<cv::Rect> detect_faces(const cv::Mat& img, const std::string& global_path);
