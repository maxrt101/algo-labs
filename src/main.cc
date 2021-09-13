/**
 * @file   main.cc
 * @author maxrt101
 */

#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cassert>

#include "stack.h"

constexpr auto k_reset = "\u001b[0m";
constexpr auto k_red = "\u001b[31m";
constexpr auto k_green = "\u001b[32m";

/**
 * Represents a test
 */
struct Test {
  std::string name;
  std::function<bool()> test_function;
};

static const std::vector<Test> tests {
  {"Push/Pop Test", []() -> bool {
    Stack<int> stack;
    const std::array<int, 4> numbers {10, 25, 50, 100};
    
    std::for_each(numbers.begin(), numbers.end(), std::bind(&Stack<int>::push, std::ref(stack), std::placeholders::_1));
    
    if (stack.size() != numbers.size()) {
      return false;
    }
    
    std::for_each(numbers.rbegin(), numbers.rend(), [&stack](int number){
      if (stack.pop() != number) {
        return false;
      }
    });
    
    return true;
  }},

  {"Peak Test", []() -> bool {
    Stack<int> stack;
    const std::array<int, 4> numbers {10, 25, 50, 100};
    
    std::for_each(numbers.begin(), numbers.end(), std::bind(&Stack<int>::push, std::ref(stack), std::placeholders::_1));
  
    for (int i = 0; i < stack.size(); i--) {
      if (stack.peak(i) != numbers[numbers.size()-1-i]) {
        return false;
      }
    }

    return true;
  }},

  {"Find Test", []() -> bool {
    Stack<int> stack;
    const std::array<int, 4> numbers {10, 25, 50, 100};
    const int number = numbers[2];
    
    std::for_each(numbers.begin(), numbers.end(), std::bind(&Stack<int>::push, std::ref(stack), std::placeholders::_1));

    auto res = std::find(numbers.rbegin(), numbers.rend(), number);

    if (res == numbers.rend()) {
      return false;
    }

    if (res - numbers.rbegin() != stack.find(number)) {
      return false;
    }

    return true;
  }},

  {"Clear Test", []() -> bool {
    Stack<int> stack;
    const std::array<int, 4> numbers {10, 25, 50, 100};
    
    std::for_each(numbers.begin(), numbers.end(), std::bind(&Stack<int>::push, std::ref(stack), std::placeholders::_1));

    if (stack.size() == 0) {
      return false;
    }

    stack.clear();

    if (stack.size() != 0) {
      return false;
    }

    return true;
  }},
  
  {"Underflow Test", []() -> bool {
    Stack<int> stack;
  
    try {
      stack.pop();
    } catch (std::underflow_error& e) {
      return true;
    }

    return false;
  }}
};

static void handleTestResult(const std::string& test_name, bool test_result) {
  if (test_result) {
    std::cout << "[ " << k_green << " OK " << k_reset << " ] ";
  } else {
    std::cout << "[ " << k_red << "FAIL" << k_reset << " ] ";
  }
  std::cout << test_name << std::endl;
  if (!test_result) {
    exit(1);
  }
}

int main(int argc, char** argv) {
  std::cout << "Stack test" << std::endl;

  for (auto& test : tests) {
    handleTestResult(test.name, test.test_function());
  }

  return 0;
}

