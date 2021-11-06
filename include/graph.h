/**
 * Kruskal's algorithm for finding minimum spanning tree
 *
 * @file   graph.h
 * @author maxrt101
 */
#ifndef _KRUSKALS_H
#define _KRUSKALS_H

#include <algorithm>
#include <vector>
#include <map>

template <typename V = char, typename T = int>
class Vertex {
 public:
  V start, end;
  T distance;

  inline Vertex(V start, V end, T distance) : start(start), end(end), distance(distance) {}
};

template <typename V = char, typename T = int>
class Graph {
 public:
  using VertexMap = std::map<V, std::map<V, T>>;
  using VertexVec = std::vector<Vertex<V, T>>;

 private:
  mutable VertexMap m_data;

 public:
  inline Graph() {}

  inline void print() const {
    for (const auto& [start, dest] : m_data) {
      for (const auto& [end, distance] : dest) {
        std::cout << start << " -> " << end << " = " << distance << std::endl;
      }
    }
  }

  inline void addEdge(V start, V end, T distance) {
    m_data[start][end] = distance;
    m_data[end][start] = distance;
  }

  inline std::map<V, T>& operator[](V vertex) {
    return m_data[vertex];
  }

  inline bool operator==(const Graph& rhs) const {
    for (const auto& [start, dest] : m_data) {
      for (const auto& [end, dist] : dest) {
        if (rhs.m_data.find(start) == rhs.m_data.end()
         || rhs.m_data[start].find(end) == rhs.m_data[start].end()
         || rhs.m_data[start][end] != dist)
          return false;
      }
    }
    return true;
  }

  inline VertexVec toVector() const {
    VertexVec result;
    for (const auto& [start, dest] : m_data) {
      for (const auto& [end, dist] : dest) {
        result.push_back(Vertex(start, end, dist));
      }
    }
    return result;
  }

  // Builds Minimum Spanning Tree using Kruskal's agorithm
  inline Graph buildMST() const {
    auto graph = toVector();
    std::vector<V> parent;
    Graph result;

    for (int i = 0; i < m_data.size(); i++) {
      parent.push_back(i);
    }

    std::sort(graph.begin(), graph.end(),
      [](const auto& lhs, const auto& rhs) -> bool {
        return lhs.distance < rhs.distance;
      });

    for (const auto& vertex : graph) {
      V u = findSet(parent, vertex.start);
      V v = findSet(parent, vertex.end);
      if (u != v) {
        result.addEdge(vertex.start, vertex.end, vertex.distance);
        unionSet(parent, u, v);
      }
    }

    return result;
  }

 private:
  V findSet(const std::vector<V>& parent, V i) const {
    if (i == parent[i]) {
      return i;
    } else {
      return findSet(parent, parent[i]);
    }
  }

  void unionSet(std::vector<V>& parent, V u, V v) const {
    parent[u] = parent[v];
  }
};

#endif

