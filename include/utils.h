#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include <vector>
#include <cstdint>

/**
 * Splits string by delimiter
 * @param str String to split
 * @param ch Delimiter character
 * @return Vector of tokens
 */
std::vector<std::string> split(const std::string& str, const char ch);

/**
 * Transforms string vector to int vector, given that every element
 * of the input vector can be converted
 * @param vec Input string vector
 * @return Vector of ints
 * @throws std::invalid_argument, std::out_of_range
 */
std::vector<uint64_t> vec_stoull(const std::vector<std::string>& vec);

#endif

