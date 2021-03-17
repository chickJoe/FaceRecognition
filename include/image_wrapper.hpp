#pragma once

#include <opencv2/opencv.hpp>
#include <json/json.h>

// wrapper under image which detects and stores faces
class image_wrapper
{
public:
	explicit image_wrapper(const std::string& path);

	// checks image emptiness
	bool empty() const;
	// checks faces exsisting
	bool has_faces() const;
	// blurs image's faces
	void blur_faces();
	// store processed image
	void store() const;
	// convert faces coordinates to JSON
	Json::Value to_json() const;
	// return path of image
	std::string get_key() const;

private:
	cv::Mat _img;
	std::string _path;
	std::vector<cv::Rect> _faces;
};
