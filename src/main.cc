/**
 * Kruskal's algorithm tests
 *
 * @file   main.cc
 * @author maxrt101
 */

#include <mrt/test/framework.h>
#include <iostream>

#include "graph.h"

int main(int argc, char ** argv) {
  mrt::test::TestFramework testFramework;

  using Graph = Graph<int, int>;

  testFramework.addTest({"Test 1", []() -> bool {
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 1);
  
    Graph expected;
    expected.addEdge(0, 1, 1);
    expected.addEdge(0, 2, 2);
    expected.addEdge(1, 4, 1);
    expected.addEdge(2, 3, 2);
    expected.addEdge(4, 5, 1);
    
    auto res = g.buildMST();

    return res.graph == expected;
  }});

  testFramework.addTest({"Test 2", []() -> bool {
    Graph g;
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 21);
    g.addEdge(1, 2, 18);
    g.addEdge(1, 3, 22);
    g.addEdge(2, 3, 13);
    g.addEdge(3, 2, 13);
    
    Graph expected;
    expected.addEdge(0, 1, 10);
    expected.addEdge(1, 2, 18);
    expected.addEdge(2, 3, 13);

    auto res = g.buildMST();

    return res.graph == expected;
  }});

  testFramework.addTest({"Test 3", []() -> bool {
    Graph g;
    g.addEdge(0, 1, 9);
    g.addEdge(0, 2, 75);
    g.addEdge(1, 2, 95);
    g.addEdge(1, 3, 19);
    g.addEdge(1, 4, 42);
    g.addEdge(2, 3, 51);
    g.addEdge(3, 4, 31);

    Graph expected;
    expected.addEdge(0, 1, 9);
    expected.addEdge(1, 3, 19);
    expected.addEdge(2, 3, 51);
    expected.addEdge(3, 4, 31);
    
    auto res = g.buildMST();

    return res.graph == expected;
  }});
  
  testFramework.addTest({"Test 4", []() -> bool {
    Graph g;

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 3);
    g.addEdge(0, 4, 5);
    g.addEdge(4, 5, 3);
    g.addEdge(5, 1, 6);
    g.addEdge(0, 5, 2);
    g.addEdge(0, 2, 7);

    auto res = g.buildMST();

    return res.weight == 9;
  }});

  return !testFramework.run(true);
}

