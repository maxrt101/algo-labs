/**
 * @file   main.cc
 * @author maxrt101
 */

#include <iostream>

#include "stack.h"

int main(int argc, char** argv) {
  std::cout << "Stack test" << std::endl;

  Stack<int> stack;

  std::cout << "push 10 25 50 100:\n";
  
  stack.push(10);
  stack.push(25);
  stack.push(50);
  stack.push(100);

  std::cout << "size: " << stack.size() << std::endl;

  std::cout << "last 4 elements: ";
  for (int i = 0; i < 4; i++) {
    std::cout << stack.peak(i) << " ";
  }
  std::cout << std::endl;

  std::cout << "find(10): " << stack.find(10) << std::endl;
  std::cout << "find(50): " << stack.find(50) << std::endl; 
  std::cout << "pop: " << stack.pop() << std::endl;
  std::cout << "size: " << stack.size() << std::endl;

  std::cout << "clear" << std::endl;
  stack.clear();

  std::cout << "size: " << stack.size() << std::endl;

  return 0;
}

