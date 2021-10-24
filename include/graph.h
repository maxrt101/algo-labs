/**
 * Graph & Dijkstra's algorith
 *
 * For a given source node in the graph, the algorithm finds the shortest path between that node and every other node.
 * Graph is represented by a 2D vector.
 * 
 * @file   graph.h
 * @author maxrt101
 */
#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <unordered_map>
#include <limits>
#include <cstdint>

/**
 * Graph
 *
 * @tparam V - Vertex representation type
 * @tparam T - Distance representation type
 */
template <typename V = char, typename T = int>
class Graph {
 public:
  using MapVT = std::unordered_map<V, T>;
  using MapVB = std::unordered_map<V, bool>;

 private:
  const T kMaxT = std::numeric_limits<T>::max();
  std::unordered_map<V, MapVT> m_data; // Stores adjacent nodes

 public:
  inline Graph() {}

  inline void print() {
    for (const auto& [start, dest] : m_data) {
      for (const auto& [end, distance] : dest) {
        std::cout << start << " -> " << end << " = " << distance << std::endl;
      }
    }
  }

  inline void addEdge(V start, V end, T distance) {
    m_data[start][end] = distance;
  }

  // Dijkstra's algorithm implementation
  inline std::unordered_map<V, T> getDistances(V start, int& operations) {
    MapVT dist(m_data.size());
    MapVB visited(m_data.size());

    for (const auto& [v, _] : m_data) {
      dist[v] = kMaxT;
      visited[v] = false;
    }

    dist[start] = 0;

    for (const auto& [v, _] : dist) {
      MapVT data = m_data[v];
      data[v] = 0;
      V m = minimalDistance(dist, data, visited, operations);
      visited[m] = true;
      for (const auto& [v, _] : m_data[m]) {
        operations++;
        if (!visited[v] && m_data[m][v]
         && dist[m] != kMaxT
         && dist[m] + m_data[m][v] < dist[v]) {
          dist[v] = dist[m] + m_data[m][v];
        }
      }
    }

    return dist;
  }

 private:
  inline V minimalDistance(MapVT& dist, const MapVT& adjacent, MapVB& visited, int& operations) {
    T minimum = kMaxT;
    V vertex;

    for (const auto& [v, d] : adjacent) {
      operations++;
      if (!visited[v] && dist[v] <= minimum) {
        minimum = dist[v];
        vertex = v;
      }
    }
    return vertex;
  }
};

#endif

