#ifndef _BTREE_H
#define _BTREE_H

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
    printNode(m_root, m_size, true);
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

  inline void printNode(NodeType* node, int level, bool endl) {
    if (node) {
      for (int i = 0; i < level; i++) std::cout << " ";
      //std::cout << node->m_data;
      printf("%2d", node->m_data);
      if (endl) std::cout << std::endl;
      printNode(node->m_left, level-2, false);
      printNode(node->m_right, level+2, true);
    }
  }

 private:
  NodeType* m_root = nullptr;
  SizeType m_size = 0;

};

#endif

