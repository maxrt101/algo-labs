/**
 * String Utilities Implementation
 *
 * @file   utils.cc
 * @author maxrt101
 */
#include <algorithm>
#include <sstream>
#include <cctype>

#include "discount.h"
#include "utils.h"

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

/**
 * Transforms string vector to int vector, given that every element
 * of the input vector can be converted
 * @param vec Input string vector
 * @return Vector of ints
 * @throws std::invalid_argument, std::out_of_range
 */
std::vector<uint64_t> vec_stoull(const std::vector<std::string>& vec) {
  std::vector<uint64_t> result;

  for (const auto& element : vec) {
    auto value = std::stoull(element);
    if (value >= k_max_price) {
      throw std::out_of_range("value can't be more than " + std::to_string(k_max_price));
    }
    result.push_back(value);
  }

  return result;
}

