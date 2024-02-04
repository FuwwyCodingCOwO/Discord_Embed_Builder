#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <Windows.h>


int main(int argc, char* argv[]) {
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
	if (argc <= 1) {
		std::cout << "use \'<program_name> help\' for more information" << std::endl;
	}
	else {
		if (strcmp(argv[1], "embed_create") == 0) {
			char input[10];
			std::cout << "Would you like to save this for future use or send after creating? (Y/N)" << std::endl;
			redo:
			std::cin >> input;
			if (strcmp(input, "y") == 0 || strcmp(input, "Y") == 0) {
				std::cout << "Not implimented yet, please select a different input" << std::endl;
				goto redo;
			}
			else if ((strcmp(input, "n") == 0 || strcmp(input, "N") == 0)) {
				std::cout << "Starting basic editor"
			}
			else {
				std::cout << "Implicit usage of Y or N only, please try again\n\nWould you like to save this for future usage? (y/n)" << std::endl;
				goto redo;
			}
		}
		else if (strcmp(argv[1], "embed_send") == 0) {
			//send embed from .bin file
			std::cout << "ebmed send" << std::endl;
		}
		else if (strcmp(argv[1], "embed_delete") == 0) {
			//delete .bin file assosiated with embed
			std::cout << "ebmed delete" << std::endl;
		}
		else if (strcmp(argv[1], "embed_edit") == 0) {
			//edit .bin file containing the embed structure
			std::cout << "ebmed edit" << std::endl;
		}
		else if (strcmp(argv[1], "help") == 0) {
			std::cout << "command arguments" << std::endl << std::endl << "embed_create" << std::endl << "embed_send" << std::endl << "embed_delete" << std::endl << "embed_edit" << std::endl << std::endl << "for more information use arg \'help <command-name>\'" << std::endl;
		}
		else {
			std::cout << "use arg \'help\' for more information" << std::endl;
		}
	}

	return 0;
}
