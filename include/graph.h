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
class Edge {
 public:
  V start, end;
  T distance;

  inline Edge(V start, V end, T distance) : start(start), end(end), distance(distance) {}
};

template <typename V = char, typename T = int>
class Graph {
 public:
  using EdgeMap = std::map<V, std::map<V, T>>;
  using EdgeVec = std::vector<Edge<V, T>>;

  struct MstResult {
    Graph graph;
    T weight;
  };

 private:
  mutable EdgeMap m_data;

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

  inline EdgeVec toVector() const {
    EdgeVec result;
    for (const auto& [start, dest] : m_data) {
      for (const auto& [end, dist] : dest) {
        result.push_back(Edge(start, end, dist));
      }
    }
    return result;
  }

  // Builds Minimum Spanning Tree using Kruskal's agorithm
  inline MstResult buildMST() const {
    auto graph = toVector();
    std::map<V, V> parent;
    Graph result;
    T weight = 0;

    for (const auto& [start, _] : m_data) {
      parent[start] = start;
    }

    std::sort(graph.begin(), graph.end(),
      [](const auto& lhs, const auto& rhs) -> bool {
        return lhs.distance < rhs.distance;
      });

    for (const auto& edge : graph) {
      V u = findSet(parent, edge.start);
      V v = findSet(parent, edge.end);
      if (u != v) {
        result.addEdge(edge.start, edge.end, edge.distance);
        weight += edge.distance;
        unionSet(parent, u, v);
      }
    }

    return MstResult{result, weight};
  }

 private:
  V findSet(std::map<V, V>& parent, V i) const {
    if (i == parent[i]) {
      return i;
    } else {
      return findSet(parent, parent[i]);
    }
  }

  void unionSet(std::map<V, V>& parent, V u, V v) const {
    parent[u] = parent[v];
  }
};

#endif

