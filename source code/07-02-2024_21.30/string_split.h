#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR
#ifndef STRING
#define STRING
#include <string>
#endif // !STRING
#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H
inline std::vector<std::string> splitString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = input.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(input.substr(start));
    return tokens;
}
#endif // !STRING_SPLIT_H