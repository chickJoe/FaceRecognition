#include "../include/image_wrapper.hpp"
#include "../include/json_writer.hpp"
#include <fstream>

json_writer::json_writer(const std::string& file_name) : _file_name(file_name) {}

json_writer& json_writer::operator<<(const image_wrapper& img)
{
	_root[img.get_key()] = img.to_json();
	return *this;
}

void json_writer::store()
{
	Json::StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["indentation"] = "   ";

	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	std::ofstream outputFileStream(_file_name);
	writer->write(_root, &outputFileStream);
}
