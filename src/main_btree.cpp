
#include "btree.h"

#include <iostream>


int main() {
    BTree<int, 10>* bt = new BTree<int, 10>();

    for (int i = 0; i < 20; i++) {
        bt = bt->insert(i);
    }

    std::cout << bt->tree_repr([=] (int key) {return std::to_string(key);});
}