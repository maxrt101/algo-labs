/**
 * Dijkstra's algorithm tests
 *
 * @file   main.cc
 * @author maxrt101
 */

#include <mrt/container_utils.h>
#include <mrt/test/framework.h>
#include <mrt/args/args.h>

#include "graph.h"

#include <iostream>

int main(int argc, char ** argv) {
  mrt::test::TestFramework testFramework;

  using Graph = Graph<char, int>;

  testFramework.addTest({"Test 1", []() -> bool {
    Graph g;

    g.addEdge('A', 'B', 1);
    g.addEdge('A', 'C', 2);
    g.addEdge('B', 'A', 1);
    g.addEdge('B', 'D', 5);
    g.addEdge('B', 'E', 1);
    g.addEdge('C', 'A', 2);
    g.addEdge('C', 'D', 2);
    g.addEdge('C', 'E', 3);
    g.addEdge('D', 'B', 5);
    g.addEdge('D', 'C', 2);
    g.addEdge('D', 'E', 2);
    g.addEdge('D', 'F', 2);
    g.addEdge('E', 'B', 1);
    g.addEdge('E', 'C', 3);
    g.addEdge('E', 'D', 2);
    g.addEdge('E', 'F', 1);
    g.addEdge('F', 'D', 2);
    g.addEdge('F', 'E', 1);

    int operations = 0;
    const Graph::MapVT expected {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 4}, {'E', 2}, {'F', 3}};
    auto result = g.getDistances('A', operations);

    std::cout << "Operations: " << operations << std::endl;

    return expected == result;
  }});

  testFramework.addTest({"Test 2", []() -> bool {
    Graph g;

    g.addEdge('A', 'B', 3);
    g.addEdge('A', 'C', 1);
    g.addEdge('B', 'A', 3);
    g.addEdge('B', 'C', 7);
    g.addEdge('B', 'D', 5);
    g.addEdge('B', 'E', 1);
    g.addEdge('C', 'A', 1);
    g.addEdge('C', 'B', 7);
    g.addEdge('C', 'D', 2);
    g.addEdge('D', 'B', 5);
    g.addEdge('D', 'C', 2);
    g.addEdge('D', 'E', 7);
    g.addEdge('E', 'B', 1);
    g.addEdge('E', 'D', 7);

    int operations = 0;
    const Graph::MapVT expected {{'A', 1}, {'B', 4}, {'C', 0}, {'D', 2}, {'E', 5}};
    auto result = g.getDistances('C', operations);
    
    std::cout << "Operations: " << operations << std::endl;

    return expected == result;
  }});

  return !testFramework.run(true);
}

