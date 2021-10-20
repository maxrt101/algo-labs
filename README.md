# Lab 4

## Task:
Implement Dijkstra's algorithm.  

## Algorithm description:
For a given source node in the graph, the algorithm finds the shortest path between that node and every other.  

Let the node at which we are starting at be called the initial node. Let the distance of node Y be the distance from the initial node to Y. Dijkstra's algorithm will initially start with infinite distances and will try to improve them step by step.  

1. Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.  
2. Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes. Set the initial node as current.  
3. For the current node, consider all of its unvisited neighbours and calculate their tentative distances through the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbour B has length 2, then the distance to B through A will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, the current value will be kept.  
4. When we are done considering all of the unvisited neighbours of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.  
5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.  
6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.  

## How to run:  
Unix like OSs (Linux, MacOS):  
Dependencies: `make`, `gcc` or `clang`  
Run:  
 - Clone the repo  
 - `cd algo_labs && git chekout lab4 && git submodule update --init`  
 - `make`  
 - `./build/bin/dijkstra`  

Widows: unsupported  

