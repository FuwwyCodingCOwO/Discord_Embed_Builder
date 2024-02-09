#ifndef CHECK_FOLDER_EXISTS_H
#define CHECK_FOLDER_EXIStS_H
#include <filesystem>
#include <string>
#pragma warning(disable : 4996)
inline void folder_existance(std::string path_to_folder) {
	if (std::filesystem::is_directory(path_to_folder)) {
	}
	else{
		std::filesystem::create_directory(path_to_folder);
	}
}
#endif