#include "../include/image_wrapper.hpp"
#include <face_detector.hpp>

static Json::Value to_json(const cv::Rect& rect)
{
	Json::Value coords;
	coords["topLeftPoint"]["x"] = rect.x;
	coords["topLeftPoint"]["y"] = rect.y;
	coords["bottomRightPoint"]["x"] = rect.x + rect.width;
	coords["bottomRightPoint"]["y"] = rect.y + rect.height;
	return coords;
}

image_wrapper::image_wrapper(const std::string& path) : _img(cv::imread(path)),
                                                        _path(path),
                                                        _faces(detect_faces(_img, _path)) {}

bool image_wrapper::empty() const
{ 
    return _img.empty();
}

bool image_wrapper::has_faces() const
{
    return !_faces.empty();
}

void image_wrapper::blur_faces() 
{
    for (const auto& face : _faces)
        cv::GaussianBlur(_img(face), _img(face), cv::Size(151, 151), 0, 0);
}

void image_wrapper::store() const
{
    cv::Mat final_img;
    cv::resize(_img, final_img, cv::Size(), 0.5, 0.5);
    cv::imwrite(_path.substr(0, _path.find(".")) + "_processed.jpg", final_img);
}

Json::Value image_wrapper::to_json() const
{
    Json::Value array;
    for (int i = 0; i < _faces.size(); ++i)
        array[i] = ::to_json(_faces[i]);

    return array;
}

std::string image_wrapper::get_key() const
{
    return _path;
}