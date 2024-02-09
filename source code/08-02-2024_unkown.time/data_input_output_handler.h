#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif // !VECTOR
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR
#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H
#include "string_split.h"
#endif // !STRING_SPLIT_H
#ifndef STRING
#define STRING
#include <string>
#endif // !STRING
#ifndef DATA_INPUT_OUTPUT_HANDLER_H
#define DATA_INPUT_OUTPUT_HANDLER_H
#include "check_folder_exists.h"
namespace data {
	namespace save {
		std::ofstream input_file;
		inline void string(std::string file_path, std::string project_directory, std::string package_name, std::string data) {
			folder_existance(file_path + "\\" + project_directory);
			input_file.open(file_path + "\\" + project_directory + "\\" + package_name + ".txt");
			input_file << data;
			input_file.close();
		}
		inline void vector(std::string file_path, std::string project_directory, std::string package_name, std::vector<std::string> data) {
			folder_existance(file_path + "\\" + project_directory);
			input_file.open(file_path + "\\" + project_directory + "\\" + package_name + ".txt");
			for (int i = 0; i < data.size(); i++) {
				input_file << data[i];
				if (i < data.size() - 1) {
					input_file << "|0|0";
				}
			}
			input_file.close();
		}
	}
	namespace load {
		std::ifstream output_file;
		inline std::string string(std::string file_path, std::string project_directory, std::string package_name) {
			output_file.open(file_path + "\\" + project_directory + "\\" + package_name + ".txt");
			std::string return_value;
			output_file >> return_value;
			output_file.close();
			return return_value;
		}
		inline std::vector<std::string> vector(std::string file_path, std::string project_directory, std::string package_name) {
			output_file.open(file_path + "\\" + project_directory + "\\" + package_name + ".txt");
			std::string sub_return_value;
			output_file >> sub_return_value;
			output_file.close();
			std::vector<std::string> return_value = splitString(sub_return_value, "|0|0");
			return return_value;
		}
	}
}
#endif // !DATA_INPUT_OUTPUT_HANDLER_H