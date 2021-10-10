#include <iostream>

#include "rbtree.h"

int main(int argc, char ** argv) {
  RedBlackTree<int> rbt;

  rbt.insert(50);
  rbt.insert(100);
  rbt.insert(120);
  rbt.insert(20);
  rbt.insert(45);

  rbt.print();

  return 0;
}

