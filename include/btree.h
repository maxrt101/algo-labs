#ifndef _BTREE_H
#define _BTREE_H

#include <string>
#include <vector>

template <typename T>
struct Node {
  Node<T>* m_left = nullptr;
  Node<T>* m_right = nullptr;
  T m_data;
};

template <typename T>
class BinaryTree {
 public:
  using NodeType = Node<T>;
  using SizeType = size_t;

  inline BinaryTree() {}
  inline ~BinaryTree() {
    clear();
  }

  inline void insert(T data) {
    if (m_root) {
      insertNode(data, m_root);
    } else {
      m_root = new NodeType;
      m_root->m_data = data;
    }
    m_size++;
  }
  
  inline NodeType* search(T data) {
    return searchNode(data, m_root);
  }
 
  inline void print() {
    printNode("", m_root, false);
  }

  inline void clear() {
    destroyNode(m_root);
  }
  
 private:
  inline void destroyNode(NodeType* node) {
    if (node) {
      destroyNode(node->m_left);
      destroyNode(node->m_right);
      delete node;
    }
  }

  inline void insertNode(T data, NodeType* node) {
    if (data < node->m_data) {
      if (node->m_left) {
        insertNode(data, node->m_left);
      } else {
        node->m_left = new NodeType;
        node->m_left->m_data = data;
      }
    } else if (data >= node->m_data) {
      if (node->m_left) {
        insertNode(data, node->m_right);
      } else {
        node->m_right = new NodeType;
        node->m_right->m_data = data;
      }
    }
  }

  inline NodeType* searchNode(T data, NodeType* node) {
    if (node) {
      if (data == node->m_data) {
        return node;
      }
      if (data < node->m_data) {
        return searchNode(data, node->m_left);
      } else {
        return searchNode(data, node->m_right);
      }
    } else {
      return nullptr;
    }
  }

  inline void printNode(const std::string& prefix, NodeType* node, bool is_left) {
    if (node) {
      std::cout << prefix;
      if (is_left) {
        std::cout << "├──";
      } else {
        std::cout << "└──";
      }
      std::cout << node->m_data << std::endl;
      printNode(prefix + (is_left ? "|    " : "     "), node->m_left, true);
      printNode(prefix + (is_left ? "|    " : "     "), node->m_right, false);
    }
    
  }

 private:
  NodeType* m_root = nullptr;
  SizeType m_size = 0;
};

#endif

