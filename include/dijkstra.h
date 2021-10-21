/**
 * Dijkstra's algorith
 *
 * For a given source node in the graph, the algorithm finds the shortest path between that node and every other node.
 * Graph is represented by a 2D vector.
 * 
 * @file   dijkstra.h
 * @author maxrt101
 */


#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include <vector>
#include <limits>
#include <cstdint>

template <typename T>
using Graph = std::vector<std::vector<T>>;

template <typename T>
inline int dijkstraMinimalDistance(const std::vector<T>& dist, const std::vector<bool>& visited, int& operations) {
  const T MAX_T = std::numeric_limits<T>::max();

  int minimum = MAX_T, index;

  for (int i = 0; i < dist.size(); i++) {
    operations++;
    if (!visited[i] && dist[i] <= minimum) {
      minimum = dist[i];
      index = i;
    }
  }
  return index;
}

template <typename T, typename DistanceType = int>
inline std::vector<T> dijkstra(Graph<T> graph, DistanceType src, int& operations) {
  const T MAX_T = std::numeric_limits<T>::max();

  std::vector<T> dist(graph.size());
  std::vector<bool> visited(graph.size());
  
  for (int i = 0; i < dist.size(); i++) {
    dist[i] = MAX_T;
    visited[i] = false;
  }

  dist[src] = 0;

  for (int i = 0; i < dist.size(); i++) {
    int m = dijkstraMinimalDistance(dist, visited, operations);
    visited[m] = true;
    for (int i = 0; i < dist.size(); i++) {
      operations++;
      if (!visited[i] && graph[m][i]
       && dist[m] != MAX_T
       && dist[m] + graph[m][i] < dist[i]) {
        dist[i] = dist[m] + graph[m][i];
      }
    }
  }
  return dist;
}

#endif

