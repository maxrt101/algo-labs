# Lab 5

## Task:
Implement Kruskal's algorithm for building minimal spanning trees.  

## Algorithm description:
MST - A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
Kruskal's algorithm - finds a minimum spanning forest of an undirected edge-weighted graph. If the graph is connected, it finds a minimum spanning tree. It is a greedy algorithm as in each step it adds the next lowest-weight edge that will not form a cycle to the minimum spanning forest.
- Create a forest F (a set of trees), where each vertex in the graph is a separate tree  
- Create a set S containing all the edges in the graph  
- While S is nonempty and F is not yet spanning  
  - Remove an edge with minimum weight from S  
  - If the removed edge connects two different trees then add it to the forest F, combining two trees into a single tree  
At the termination of the algorithm, the forest forms a minimum spanning forest of the graph. If the graph is connected, the forest has a single component and forms a minimum spanning tree.  

## How to run:
Unix like OSs (Linux, MacOS):  
Dependencies: `make`, `gcc` or `clang`  
Run:  
 - Clone the repo  
 - `cd algo_labs && git checkout lab5 && git submodule update --init`  
 - `make`  
 - `./build/bin/kruskals`  

Windows: unsupported

