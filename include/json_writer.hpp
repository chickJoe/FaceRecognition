#pragma once

#include <json/json.h>

class image_wrapper;

// wrapper under Json::Value to hide internal logic of writing and storing to json file
class json_writer
{
public:
	explicit json_writer(const std::string& file_name);

	json_writer& operator<<(const image_wrapper& img);

	void store();

private:
	Json::Value _root;
	std::string _file_name;
};