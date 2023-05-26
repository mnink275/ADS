#pragma once

#include <vector>

// Union Find / DFS / Disjoint-Set-Union
// with path compression and rank unification (based on the tree depth)
class UnionFind {
 public:
  UnionFind(const int max_vertex_num) {
    parent_.resize(max_vertex_num + 1);
    rank_.resize(max_vertex_num + 1);
  }

  void makeSet(const int vertex) {
    parent_[vertex] = vertex;
    rank_[vertex] = 0;
  }

  int findSet(const int vertex) {
    if (vertex == parent_[vertex]) return vertex;
    return parent_[vertex] = findSet(parent_[vertex]);
  }

  void unionSets(int vertex_a, int vertex_b) {
    vertex_a = findSet(vertex_a);
    vertex_b = findSet(vertex_b);
    if (vertex_a != vertex_b) {
      if (rank_[vertex_a] < rank_[vertex_b]) std::swap(vertex_a, vertex_b);
      parent_[vertex_b] = vertex_a;
      if (rank_[vertex_a] == rank_[vertex_b]) ++rank_[vertex_a];
    }
  }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};