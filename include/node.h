#ifndef _NODE_H
#define _NODE_H

#include "color.h"

template <typename T>
struct Node {
  Node<T>* parent = nullptr;
  Node<T>* left = nullptr;
  Node<T>* right = nullptr;
  T data;
  Color color;

  inline Node() = default;
  inline Node(const T& data) : data(data) {}
  inline Node(Node<T>* parent) : parent(parent) {}
  inline Node(const T& data, Node<T>* parent) : data(data), parent(parent) {}
  inline Node(const T& data, Node<T>* parent, Node<T>* left, Node<T>* right, Color color)
    : data(data), parent(parent), left(left), right(right), color(color) {}
};

#endif

