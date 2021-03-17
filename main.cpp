#include <iostream>
#include <opencv2/opencv.hpp>

#include "include/json_writer.hpp"
#include "include/image_wrapper.hpp"

int main(int argc, char const *argv[])
{
	std::string folder;

	try {
		if (argc == 2) {
			std::stringstream convert(argv[1]);
			if (!(convert >> folder) || (folder.back() != '/' && folder.back() != '\\'))
				throw "Wrong argument format";
		} else
			throw "Wrong number of arguments";

		json_writer writer(folder + "result.json");

		std::vector<std::string> files;
		cv::glob(folder, files, true);

		// processes all files in folder
		for (const auto& file : files) {
			image_wrapper img(file);
			if (img.empty())
				continue;

			writer << img;

			if (img.has_faces()) {
				img.blur_faces();
				img.store();
			}
		}

		writer.store();

	} catch (const char* msg) {
		std::cerr << msg << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Unknown exception" << std::endl;
		return 1;
	}

	return 0;
}