/**
 * Utils
 * 
 * @file   utils.h
 * @author maxrt101
*/

#ifndef _UTILS_H
#define _UTILS_H

#include <vector>
#include <string>

constexpr auto kInFile = "ijones.in";
constexpr auto kOutFile = "ijones.out";

std::vector<std::string> loadFromFile(const std::string& filename);

#endif
