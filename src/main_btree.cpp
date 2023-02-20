
#include "btree.h"

#include <iostream>


int main() {
    BTree<int, 10> bt;
    std::cout << bt.used_children << std::endl;
    std::cout << bt.leaf << std::endl;
    std::cout << bt.min_degree << std::endl;
}