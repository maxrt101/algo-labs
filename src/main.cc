/**
 */

#include <iostream>

#include "btree.h"

int main(int argc, char ** argv) {
  BinaryTree<int> btree;

  btree.insert(10);
  btree.insert(20);
  btree.insert(5);
  btree.insert(50);

  std::cout << btree.search(20)->m_data << std::endl;

  btree.print();

  return 0;
}

