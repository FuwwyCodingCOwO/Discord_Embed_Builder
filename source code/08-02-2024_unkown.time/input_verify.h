#ifndef STRING
#define STRING
#include <string>
#endif
#ifndef INPUT_VERIFY_H
#define INPUT_VERIFY_H
inline bool containsOnlySpaces(const std::string& str) {
    return str.find_first_not_of(' ') == std::string::npos;
}
#endif