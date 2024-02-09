#ifndef STRING
#define STRING
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef COLOUR_H
#define COLOUR_H
#include "colour.h"
#endif // !COLOUR_H

#ifndef STANDARD_ERROR_H
#define STANDARD_ERROR_H

namespace error {
	inline void error_handler(std::string error, std::string argument) {
		std::cerr << colour::RED << error << argument << colour::RESET << std::endl << std::endl;
	}
}

#endif // !STANDARD_ERROR_H
