#include "kmp.h"

#include <iostream>
#include <vector>

static std::vector<int64_t> generatePartialMatchTable(const std::string& substring) {
  std::vector<int64_t> table(substring.size(), 0);
  
  for (int i = 1, j = 0; i < substring.size(); i++) {
    if (substring[i] == substring[j]) {
      table[i++] = j++;
    } else {
      if (j != 0) {
        j = table[j - 1];
      } else {
        table[i++] = 0;
      }
    }
  }

  return table;
}

std::vector<int64_t> kmp(const std::string& input, const std::string& substring) {
  if (!input.size() || !substring.size() || input.size() < substring.size()) {
    return {};
  }

  std::vector<int64_t> partial_match = generatePartialMatchTable(substring);
  std::vector<int64_t> match;

  /*DEBUG*/ std::cout << "prefix: "; for (const auto& x : partial_match) std::cout << x << " "; std::cout << std::endl;

  for (int i = 0, j = 0; i < input.size(); ) {
    if (input[i] == substring[j]) {
      j++;
      i++;
    }

    if (j == substring.size()) {
      match.push_back(i - j);
      j = partial_match[j - 1];
    } else if (i < input.size() && input[i] != substring[j]) {
      if (j != 0) {
        j = partial_match[j - 1];
      } else {
        i++;
      }
    }
  }

  return match;
}

