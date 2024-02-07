#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#pragma warning(disable : 4996)
void initializer(), editor(int mode), saver(), sender();
std::string path = std::string(std::getenv("APPDATA")) + "\\Discord_Embed_Project";
int setup() {
	if (std::filesystem::is_directory(path)) {
		return 0;
	}
	else {
		bool result = std::filesystem::create_directory(path);
		if (result) {
			return 0;
		}
		else {
			return 1;
		}
	}
}
struct discord_embed_struct_create {
	std::string token;
	std::string message_optional;
	std::string embed_name;
	std::string embed_description;
	std::string embed_color;
	std::vector<std::string> fields_name;
	std::vector<std::string> fields_description;
	std::vector<std::string> fields_inline;
};
discord_embed_struct_create main_struct_one;
void initializer() {
	std::cout << "Please select an Option\n\n"
		"1. Open embed data from existing file\n"
		"2. Create new embed data\n"
		"3. Create one-time use embed data\n\n"
		"Enter the number corresponding to your choice: ";
	std::string input;
	redo:
	std::cin >> input;
	if (input == "1") {
		std::cout << "Please select one of these options\n\n"
			"1. Open embed file in editor\n"
			"2. Open embed file in sender\n\n"
			"Enter the number corresponding to your choice: ";
		opt_one_redo:
		std::cin >> input;
		if (input == "1") {
			std::cout << "Enter file name below or use '.list' to view available files names";
		}
		else if (input == "2") {}
		else {
			std::cerr << "InvalidCommandException: The specified command does not exist\nEnter option corresponding to your choice: ";
			goto opt_one_redo;
		}
	}
	else if (input == "2") {
		editor(0);
	}
	else if (input == "3") {
		editor(1);
	}
	else {
		std::cerr << "InvalidCommandException: The specified command does not exist\nEnter option corresponding to your choice: ";
		goto redo;
	}
}
void editor(int mode) {
}
void saver() {
	//utilize "null" characther "/0/0" for vector saving scheme
	//example "vector.extension" "apple/0/0banna/0/0car"
}
void sender() {
}
int main(int argc, char* argv[]) {
	if (setup() != 0) {
		std::cerr << "Critical error" << std::endl;
		return 1;
	}
	initializer();
	return 0;
}