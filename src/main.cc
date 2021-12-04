#include "kmp.h"

#include <iostream>

int main(int argc, const char ** argv) {

  auto res = kmp("abcdeabc", "abc");

  /*DEBUG*/ std::cout << "result: "; for (const auto& x : res) std::cout << x << " "; std::cout << std::endl; 

  return 0;
}

