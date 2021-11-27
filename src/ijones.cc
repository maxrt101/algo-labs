/**
 * Indiana Jones Implementation
 *
 * @file   ijones.cc
 * @author maxrt101
*/

#include "ijones.h"

#include <map>
#include <iostream>

static void validate(const std::vector<std::string>& input) {
  if (input.size() < 0 || input.size() > kMaxSize) {
    throw "Height is zero or too big";
  }
  int len = input[0].size();
  if (len > kMaxSize) {
    throw "Width is too big";
  }
  for (const auto& s : input) {
    if (len != s.size()) {
      throw "Input is not a map";
    }
  }
}

template <typename K, typename V>
static V getOr(const std::map<K, V>& map, K key, V value) {
  if (map.find(key) != map.end()) {
    return map.at(key);
  }
  return value;
}

int ijones(const std::vector<std::string>& input) {
  validate(input);

  std::vector<std::vector<int>> count;
  for (int i = 0; i < input.size(); i++) {
    count.push_back(std::vector<int>(input[0].size()));
    count[i][0] = 1;
  }

  std::map<char, int> prev;

  for (const auto& s : input) {
    if (prev.find(s[0]) != prev.end()) {
      prev[s[0]] = prev[s[0]]+1;
    } else {
      prev[s[0]] = 1;
    }
  }

  for (int i = 1; i < input[0].size(); i++) {
    std::map<char, int> current;
    for (int j = 0; j < input.size(); j++) {
      char ch = input[j][i];
      count[j][i] = getOr(prev, ch, 0);
      if (ch != input[j][i-1]) {
        count[j][i] += count[j][i-1];
      }
      current[ch] = getOr(current, ch, 0) + count[j][i];
    }

    for (const auto& [k, _] : current) {
      prev[k] = getOr(prev, k, 0) + current[k];
    }
  }

  int exit_count = count[0][input[0].size()-1];
  return input.size() > 1 ? exit_count + count[input.size()-1][input[0].size()-1] : exit_count;
}
