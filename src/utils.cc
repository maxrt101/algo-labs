/**
 * Utility functions
 *
 * @file   utils.cc
 * @author maxrt101
 */

#include <algorithm>
#include <sstream>
#include <cctype>

#include "utils.h"

/**
 * Transforms string to lowercase
 * @param str String to transform
 * @return Transformed string
 */
std::string to_lowercase(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), [](unsigned int c) { return std::tolower(c); });
  return str;
}

/**
 * Capitalises string (makes 1st letter uppercase)
 * @param str Input string
 * @return Capitalised string
 */
std::string capitalise(std::string str) {
  str[0] = std::toupper(str[0]);
  return str;
}

/**
 * Splits string by delimiter
 * @param str String to split
 * @param ch Delimiter character
 * @return Vector of tokens
 */
std::vector<std::string> split(const std::string& str, const char ch) {
  std::stringstream ss(str);
  std::string token;
  std::vector<std::string> tokens;

  while (std::getline(ss, token, ch)) {
    tokens.push_back(token);
  }

  return tokens;
}

