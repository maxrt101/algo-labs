#ifndef _UTILS_H
#define _UTILS_H

#include <vector>
#include <string>

/**
 * Transforms string to lowercase
 * @param str String to transform
 * @return Transformed string
 */
std::string to_lowercase(std::string str);

/**
 * Capitalises string (makes 1st letter uppercase)
 * @param str Input string
 * @return Capitalised string
 */
std::string capitalise(std::string str);

/**
 * Splits string by delimiter
 * @param str String to split
 * @param ch Delimiter character
 * @return Vector of tokens
 */
std::vector<std::string> split(const std::string& str, const char ch);

#endif
