#ifndef STRING
#define STRING
#include <string>
#endif // !STRING
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !STRING
#ifndef VECTOR_SIZE_H
#define VECTOR_SIZE_H
inline bool vector_size(std::vector<std::string> input, int size) {
	if (input.size() == size) {
		return true;
	}
	else {
		return false;
	}
}
#endif // !VECTOR_SIZE_H