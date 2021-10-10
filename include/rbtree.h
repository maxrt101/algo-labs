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

  inline RedBlackTree() {
    m_nil = new NodeType();
    m_nil->parent = m_nil;
    m_nil->left = m_nil;
    m_nil->right = m_nil;
    m_nil->color = Color::BLACK;
    m_root = m_nil;
  }
  
  inline ~RedBlackTree() {
    deleteNode(m_root);
    m_root = nullptr;
    delete m_nil;
    m_nil = nullptr;
  }
 
  inline bool isPresent(const T& value) const {
    if (!m_count) return false;
    NodeType* node = search(value);
    return node && node->data == value;
  }

  inline NodeType* search(const T& value) const {
    NodeType* node = m_root;
    while (node->data != value) {
      if (value < node->data && node->left != m_nil) {
        node = node->left;
      } else if (value > node->data && node->right != m_nil) {
        node = node->right;
      } else {
        break;
      }
    }
    return node;
  }

  inline T max() const {
    return m_root ? max(m_root)->data : T();
  }

  inline T min() const {
    return m_root ? min(m_root)->data : T();
  }

  inline void insert(const T& value) {
    NodeType* node = new NodeType(value, nullptr, m_nil, m_nil, Color::RED);
    insert(node);
  }

  inline void remove(const T& value) {
    remove(m_root, value);
  }

  inline void print() const {
    printNode("", m_root, false);
  }

 private:
  inline void deleteNode(NodeType* node) {
    if (node != m_nil) return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
  }

  NodeType* min(NodeType* node) const {
    while (node->left != m_nil) {
      node = node->left;
    }
    return node;
  }

  NodeType* max(NodeType* node) const {
    while (node->right != m_nil) {
      node = node->right;
    }
    return node;
  }

  inline bool isLeftChild(NodeType* node) const {
    return (node != m_root && node != m_nil && node == node->parent->left);
  }

  inline bool hasRedChild(NodeType* node) const {
    return (node->left && node->left->color == Color::RED)
        || (node->right && node->right->color == Color::RED);
  }

  inline NodeType* getGrand(NodeType* node) const {
    if (!node) return nullptr;
    return (node == m_root || node->parent == m_root) ? nullptr : node->parent->parent;
  }

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

  inline NodeType* getBrother(NodeType* node) const {
    if (!node) return nullptr;
    return (node->parent->left == node) ? node->right : node->left;
  }

  inline void transplant(NodeType* node1, NodeType* node2) {
    if (!node1->parent) {
      m_root = node2;
    } else if (node1 == node1->parent->left) {
      node1->parent->left = node2;
    } else {
      node1->parent->right = node2;
    }
    node2->parent = node1->parent;
  }

  inline void leftRotate(NodeType* node) {
    NodeType* right = node->right;
    std::cout << "LeftRotate: " << node->data << " & " << right->data << std::endl;
    node->right = right->left;
    if (right->left != m_nil) {
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

  inline void rightRotate(NodeType* node) {
    NodeType* left = node->left;
    std::cout << "RighRotate: " << node->data << " & " << left->data << std::endl;
    node->left = left->right;
    if (left->right != m_nil) {
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

  inline void insert(NodeType* new_node) {
    NodeType *x = m_root, *y = nullptr;
    while (x != m_nil) {
      y = x;
      if (new_node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    new_node->parent = y;
    if (!y) {
      m_root = new_node;
    } else if (new_node->data < y->data) {
      y->left = new_node;
    } else {
      y->right = new_node;
    }

    if (!new_node->parent) {
      new_node->color = Color::BLACK;
      return;
    }

    if (!new_node->parent->parent) {
      return;
    }

    insertFixup(new_node);
  }

  inline void insertFixup(NodeType* new_node) {
    NodeType* node;
    while (new_node->parent->color == Color::RED) {
      if (new_node->parent == new_node->parent->parent->right) {
        node = new_node->parent->parent->left;
        if (node->color == Color::RED) {
          node->color = Color::BLACK;
          new_node->parent->color = Color::BLACK;
          new_node->parent->parent->color = Color::RED;
        } else {
          if (new_node == new_node->parent->left) {
            new_node = new_node->parent;
            rightRotate(new_node);
          }
          new_node->parent->color = Color::BLACK;
          new_node->parent->parent->color = Color::RED;
          leftRotate(new_node->parent->parent);
        }
      } else {
        node = new_node->parent->parent->right;

        if (node->color == Color::RED) {
          node->color = Color::BLACK;
          new_node->parent->color = Color::BLACK;
          new_node->parent->parent->color = Color::RED;
          new_node = new_node->parent->parent;
        } else {
          if (new_node == new_node->parent->right) {
            new_node = new_node->parent;
            leftRotate(new_node);
          }
          new_node->parent->color = Color::BLACK;
          new_node->parent->parent->color = Color::RED;
          rightRotate(new_node->parent->parent);
        }
      }
      if (new_node == m_root) {
        break;
      }
    }
    m_root->color = Color::BLACK;
  }

  inline void remove(NodeType* node, const T& key) {
    NodeType *x, *y, *z = m_nil;

    while (node != m_nil) {
      if (node->data == key) {
        z = node;
      }
      if (node->data <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == m_nil) return;

    y = z;
    Color color = y->color;
    if (z->left == m_nil) {
      x = z->right;
      transplant(z, z->right);
    } else if (z->right == m_nil) {
      x = z->left;
      transplant(z, z->left);
    } else {
      y = min(z->right);
      color = y->color;
      x = y->right;
      if (y->parent == node) {
        x->parent = y;
      } else {
        transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (color == Color::BLACK) {
      removeFixup(x);
    }
    m_count--;
  }

  inline void removeFixup(NodeType* node) {
    NodeType* s;
    while (node != m_root && node->color == Color::BLACK) {
      if (node == node->parent->left) {
        s = node->parent->right;
        if (s->color == Color::RED) {
          s->color = Color::BLACK;
          node->parent->color = Color::RED;
          leftRotate(node->parent);
          s = node->parent->right;
        }

        if (s->left->color == Color::BLACK && s->right->color == Color::BLACK) {
          s->color = Color::RED;
          node = node->parent;
        } else {
          if (s->right->color == Color::BLACK) {
            s->left->color = Color::BLACK;
            s->color = Color::RED;
            rightRotate(s);
            s = node->parent->right;
          }

          s->color = node->parent->color;
          node->parent->color = Color::BLACK;
          s->right->color = Color::BLACK;
          leftRotate(node->parent);
          node = m_root;
        }
      } else {
        s = node->parent->left;
        if (s->color == Color::RED) {
          s->color = Color::BLACK;
          s->parent->color = Color::RED;
          rightRotate(node->parent);
          s = node->parent->left;
        }

        if (s->right->color == Color::BLACK && s->right->color == Color::BLACK) {
          s->color = Color::RED;
          node = node->parent;
        } else {
          if (s->left->color == Color::BLACK) {
            s->right->color = Color::BLACK;
            s->color = Color::RED;
            leftRotate(s);
            s = node->parent->left;
          }

          s->color = node->parent->color;
          node->parent->color = Color::BLACK;
          s->left->color = Color::BLACK;
          rightRotate(node->parent);
          node = m_root;
        }
      }
    }
    node->color = Color::BLACK;
  }

  inline void printNode(const std::string& prefix, NodeType* node, bool is_left) const {
    if (node && node != m_nil) {
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
      printNode(prefix + (is_left ? "│    " : "     "), node->left, true);
      printNode(prefix + (is_left ? "│    " : "     "), node->right, false);
    } 
  }

 private:
  NodeType* m_root = nullptr;
  NodeType* m_nil = nullptr;
  SizeType m_count = 0;
};

#endif

