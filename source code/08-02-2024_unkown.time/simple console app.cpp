#include <vector>
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "string_split.h"
#include "input_verify.h"
#include "colour.h"
#include "data_input_output_handler.h"
#include "discord.h"
#include "standard_error.h"
#include "vector_size.h"
#pragma warning(disable : 4996)
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

namespace field_edit {

}

void editor(std::string file_name, int mode);
void initiate_structure_loader(std::string file_name) {
	main_struct_one.token = data::load::string(path, file_name, "token");
	main_struct_one.message_optional = data::load::string(path, file_name, "message_optional");
	main_struct_one.embed_name = data::load::string(path, file_name, "embed_name");
	main_struct_one.embed_description = data::load::string(path, file_name, "embed_description");
	main_struct_one.embed_color = data::load::string(path, file_name, "embed_color");
	main_struct_one.fields_name = data::load::vector(path, file_name, "fields_name");
	main_struct_one.fields_description = data::load::vector(path, file_name, "fields_description");
	main_struct_one.fields_inline = data::load::vector(path, file_name, "fields_inline");
}
void initiate_structure_saver(std::string file_name) {
	data::save::string(path, file_name, "token", main_struct_one.token);
	data::save::string(path, file_name, "message_optional", main_struct_one.message_optional);
	data::save::string(path, file_name, "embed_name", main_struct_one.embed_name);
	data::save::string(path, file_name, "embed_description", main_struct_one.embed_description);
	data::save::string(path, file_name, "embed_color", main_struct_one.embed_color);
	data::save::vector(path, file_name, "fields_name", main_struct_one.fields_name);
	data::save::vector(path, file_name, "fields_description", main_struct_one.fields_description);
	data::save::vector(path, file_name, "fields_inline", main_struct_one.fields_inline);
}
void file_loader() {
	std::string input;
	std::vector<std::string> input_split;
	basic_console:
	std::cout << colour::GREEN << "embed@console" << colour::RESET << " $ ";
	std::getline(std::cin, input);
	input_split = splitString(input, ".");
	if (input_split[0] == "help") {
		goto basic_console;
	}
	else if (input_split[0] == "open_from_file") {
		if (input_split.size() != 2) {
			error::error_handler("ERROR: TOO MANY OR FEW ARGUMENTS PASSED", "");
			goto basic_console;
		}
		if (containsOnlySpaces(input_split[1])) {
			std::cerr << colour::RED << "ERROR: INVALID CHARACHTER: Use charachters only for file names" << colour::RESET << std::endl << std::endl;
			goto basic_console;
		}
		std::cout << "Attemtping to open, " << input_split[1] << ", in editor" << std::endl << std::endl;
		editor(input_split[1],1);
	}
	else if (input_split[0] == "create_new") {
		if (input_split.size() != 2) {
			error::error_handler("ERROR: TOO MANY OR FEW ARGUMENTS PASSED", "");
			goto basic_console;
		}
		if (containsOnlySpaces(input_split[1])) {
			std::cerr << colour::RED << "ERROR: INVALID CHARACHTER: Use charachters only for file names" << colour::RESET << std::endl << std::endl;
			goto basic_console;
		}
		std::cout << "Attemtping to create, " << input_split[1] << ", in editor" << std::endl << std::endl;
		editor(input_split[1],0);
	}
	else if (input_split[0] == "exit") {
		std::cout << colour::BLUE << std::endl << "exiting with exit code 0" << colour::RESET << std::endl;
	}
	else if (containsOnlySpaces(input_split[0])) {
		goto basic_console;
	}
	else if (input_split[0] == "clear") {
		system("cls");
		goto basic_console;
	}
	else {
		error::error_handler("ERROR: COMMAND NOT FOUND: ", input_split[0]);
		goto basic_console;
	}
}

void editor(std::string file_name, int mode) {
	if (mode == 0) {
		//prevents next from firing accidently
	}
	else {
		initiate_structure_loader(file_name);
	}
	std::string input;
	std::vector<std::string> input_split;
	console:
	std::cout << colour::GREEN << "embed@editor" << colour::RESET << " $ ";
	std::getline(std::cin, input);
	input_split = splitString(input, ".");
	if (input_split[0] == "send") {
		std::string save_before_sending;
		std::cout << "Would you like to save embed before sending? (Y/N)" << std::endl;
		input_redo:
		std::cin >> save_before_sending;
		if (save_before_sending == "Y" || save_before_sending == "y") {
			initiate_structure_saver(file_name);
		}
		else if (save_before_sending == "N" || save_before_sending == "n") {
			//carry on
		}
		else {
			std::cerr << colour::RED << "ERROR: INPUT: Explicit usage of Y or N only" << colour::RESET << std::endl;
			error::error_handler("ERROR: INPUT: Explicit usage of Y or N only", "");
			goto input_redo;
		}
	}
	else if (input_split[1] == "view_structure") {

	}
	else if (input_split[0] == "exit") {
		std::string save_before_sending;
		std::cout << "Would you like to save embed before exiting? (Y/N)" << std::endl;
		input_redo_two:
		std::cin >> save_before_sending;
		if (save_before_sending == "Y" || save_before_sending == "y") {
			initiate_structure_saver(file_name);
		}
		else if (save_before_sending == "N" || save_before_sending == "n") {
			//carry on
		}
		else {
			error::error_handler("ERROR: INPUT: Explicit usage of Y or N only", "");
			goto input_redo_two;
		}
		std::cout << colour::BLUE << std::endl << "exiting with exit code 0" << colour::RESET << std::endl;
	}



	else if (input_split[0] == "fields") {
		if (vector_size(input_split,2)) {
			if (input_split[1] == "modify") {
				if (vector_size(input_split, 3)) {
				}
			}
			else if (input_split[1] == "insert") {

			}
			else if (input_split[1] == "delete") {
				if (vector_size(input_split, 3)) {
					if (containsOnlySpaces(input_split[1])) {
						error::error_handler("ERROR: MISSING SUBCOMMAND ARGUMENT", "");
						goto console;
					}
					else {
						error::error_handler("ERROR: SUBCOMMAND NOT FOUND: ", input_split[2]);
						goto console;
					}
					
				}
				else {
					error::error_handler("ERROR: MISSING SUBCOMMAND ARGUMENT", "");
					goto console;
				}
			}
			else if (input_split[1] == "add_new") {

			}
			else if (containsOnlySpaces(input_split[1])) {
				error::error_handler("ERROR: MISSING SUBCOMMAND ARGUMENT", "");
				goto console;
			}
			else {
				error::error_handler("ERROR: SUBCOMMAND NOT FOUND: ", input_split[1]);
				goto console;
			}
		}
		else {
			error::error_handler("ERROR: MISSING SUBCOMMAND ARGUMENT", "");
			goto console;
		}

	}


	else if (input_split[0] == "data") {
		//the non field stuff
	}
















	else if (containsOnlySpaces(input_split[0])) {
		goto console;
	}
	else {
		error::error_handler("ERROR: COMMAND NOT FOUND: ", input_split[0]);
		goto console;
	}
}

int main(int argc, char* argv[]) {
	if (setup() != 0) {
		std::cerr << "Critical error during setup" << std::endl;
		return 1;
	}
	file_loader();
	system("pause");
	return 0;
}
