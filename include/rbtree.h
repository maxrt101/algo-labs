#ifndef _RBTREE_H
#define _RBTREE_H

#include "node.h"

constexpr auto k_red = "\u001b[31m";
constexpr auto k_reset = "\u001b[0m";

template <typename T, typename N = Node<T>>
class RedBlackTree {
 public:
  using NodeType = N;
  using SizeType = size_t;

// DEBUG
  inline NodeType* getRoot() const { return m_root; }
//

  inline RedBlackTree() {}
  
  inline ~RedBlackTree() {
    deleteNode(m_root);
    m_root = nullptr;
  }

  inline NodeType* search(const T& value) const {
    NodeType* node = m_root;
    while (node->data != value) {
      if (value < node->data && node->left) {
        node = node->left;
      } else if (value > node->data && node->right) {
        node = node->right;
      } else {
        break;
      }
    }
    return node;
  }

  inline void insert(const T& value) {
    NodeType* node = new Node(value);
    if (!insert(node)) {
      delete node;
      return;
    }
    insertFixup(node);
  }

  inline void remove(const T& value) {}

  inline void print() const {
    printNode("", m_root, false);
  }

 private:
  inline void deleteNode(NodeType* node) {
    if (!node) return;

    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
  }

  /**
   */
  inline bool isLeftChild(NodeType* node) const {
    return (node != m_root && node == node->parent->left);
  }

  /**
   */
  inline NodeType* getGrand(NodeType* node) const {
    if (!node) return nullptr;
    return (node == m_root || node->parent == m_root) ? nullptr : node->parent->parent;
  }

  /**
   */
  inline NodeType* getUncle(NodeType* node) const {
    if (!node) {
      return nullptr;
    } else if (node == m_root || node->parent == m_root) {
      return nullptr;
    } else if (isLeftChild(node->parent)) {
      return getGrand(node)->right;
    } else {
      return getGrand(node)->left;
    }
  }

  /**  
   *    Z 
   *      X
   *        Y
   *
   *    Y
   *  Z   X
   */
  inline void leftRotate(NodeType* node) {
    NodeType* right = node->right;
    std::cout << "LeftRotate: " << node->data << " & " << right->data << std::endl;
    node->right = right->left;
    if (right->left) {
      right->left->parent = node;
    }
    right->parent = node->parent;
    if (!node->parent) {
      m_root = right;
    } else if (node == node->parent->left) {
      node->parent->left = right;
    } else {
      node->parent->right = right;
    }
    right->left = node;
    node->parent = right;
  }

  /**
   */
  inline void rightRotate(NodeType* node) {
    NodeType* left = node->left;
    std::cout << "RighRotate: " << node->data << " & " << left->data << std::endl;
    node->left = left->right;
    if (left->right) {
      left->right->parent = node;
    }
    left->parent = node->parent;
    if (!node->parent) {
      m_root = left;
    } else if (node == node->parent->left) {
      node->parent->left = left;
    } else {
      node->parent->right = left;
    }
    left->right = node;
    node->parent = left;
  }

  /**
   */
  inline bool insert(NodeType* new_node) {
    //T data = new_node->m_data;
    if (m_count == 0) {
      m_count = 1;
      m_root = new_node;
    } else {
      NodeType* node = search(new_node->data);
      if (new_node->data < node->data) {
        m_count++;
        node->left = new_node;
        new_node->parent = node;
      } else if (new_node->data > node->data) {
        m_count++;
        node->right = new_node;
        new_node->parent = node;
      } else {
        return false;
      }
    }
    return true;
  }

  /**
   */
  inline void insertFixup(NodeType* node) {
    node->color = Color::RED;
    while (node != m_root && node->parent->color == Color::RED) {
      NodeType* uncle = getUncle(node);
      if (uncle && uncle->color == Color::RED) {
        node->parent->color = Color::BLACK;
        uncle->color = Color::BLACK;
        getGrand(node)->color = Color::RED;
        node = getGrand(node);
      } else {
        bool parent_was_left_child = isLeftChild(node->parent);
        bool was_left_child = isLeftChild(node);
        if (parent_was_left_child && !was_left_child) {
          node = node->parent;
          leftRotate(node);
        } else if (!parent_was_left_child && was_left_child) {
          node = node->parent;
          rightRotate(node);
        }
        node->parent->color = Color::BLACK;
        getGrand(node)->color = Color::RED;
        if (parent_was_left_child) {
          rightRotate(getGrand(node));
        } else {
          leftRotate(getGrand(node));
        }
      }
    }
    m_root->color = Color::BLACK;
  }

  /**
   */
  inline void printNode(const std::string& prefix, NodeType* node, bool is_left) const {
    if (node) {
      std::cout << prefix;
      if (is_left) {
        std::cout << "├──";
      } else {
        std::cout << "└──";
      }
      std::cout
        << (node->color == Color::RED ? k_red : "")
        << node->data 
        << (node->color == Color::RED ? k_reset : "")
        << std::endl;
      printNode(prefix + (is_left ? "|    " : "     "), node->left, true);
      printNode(prefix + (is_left ? "|    " : "     "), node->right, false);
    }
    
  }

 private:
  NodeType* m_root = nullptr;
  SizeType m_count = 0;
};

#endif

