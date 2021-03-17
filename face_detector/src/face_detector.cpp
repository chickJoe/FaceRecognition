#include <face_detector.hpp>
#include <iostream>
											
std::vector<cv::Rect> detect_faces(const cv::Mat& img, const std::string& global_path) {
    std::vector<cv::Rect> faces;
    if (!img.empty()) {
        _cv_detector.detectMultiScale(img, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
        std::cout << "Image : " << global_path << " , faces amount : "  << faces.size() << std::endl;
    }

    return faces;
}
