/**
 * Dijkstra's algorithm tests
 *
 * @file   main.cc
 * @author maxrt101
 */

#include <mrt/test/framework.h>
#include <mrt/args/args.h>

#include "dijkstra.h"

#include <iostream>

int main(int argc, char ** argv) {
  mrt::test::TestFramework testFramework;

  testFramework.addTest({"Test 1", []() -> bool {
    Graph<int> g {
      {0, 1, 2, 0, 0, 0},
      {1, 0, 0, 5, 1, 0},
      {2, 0, 0, 2, 3, 0},
      {0, 5, 2, 0, 2, 2},
      {0, 1, 3, 2, 0, 1},
      {0, 0, 0, 2, 1, 0}
    };

    int operations = 0;
    const std::vector<int> expected {0, 1, 2, 4, 2, 3};
    auto result = dijkstra(g, 0, operations);
  
    std::cout << "Operations: " << operations << std::endl;

    return expected == result;
  }});

  testFramework.addTest({"Test 2", []() -> bool {
    Graph<int> g {
      {0, 3, 1, 0, 0},
      {3, 0, 7, 5, 1},
      {1, 7, 0, 2, 0},
      {0, 5, 2, 0, 7},
      {0, 1, 0, 7, 0}
    };
    
    int operations = 0;
    const std::vector<int> expected {1, 4, 0, 2, 5};
    auto result = dijkstra(g, 2, operations);
    
    std::cout << "Operations: " << operations << std::endl;

    return expected == result;
  }});

  return !testFramework.run(true);
}
