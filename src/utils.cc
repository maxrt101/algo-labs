/**
 * Utils implementation
 * 
 * @file   utils.cc
 * @author maxrt101
*/

#include <string>
#include <fstream>
#include <iostream>

#include "utils.h"

std::vector<std::string> loadFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.good()) {
    throw "Nonexistent File";
  }

  std::string sizes;
  std::getline(file, sizes);

  // if () {}

  std::vector<std::string> result;

  std::string row;
  while (getline(file, row)) {
    if (row != "") {
      result.push_back(row);
    }
  }

  return result;
}
