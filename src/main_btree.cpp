
#include <iostream>

#include "btree.h"

void print_tree(BTree<int, 3>* bt) {
    std::cout << "Result: " << std::endl;
    std::cout << bt->tree_repr([=] (int key) {
        return std::to_string(key);
    });
}

int main() {
    BTree<int, 3>* bt = new BTree<int, 3>();

    for (int i = 0; i < 15; i++) {
        std::cout << "Inserting " << i << std::endl;
        bt = bt->insert(i);
    }

    print_tree(bt);

    std::cout << "Deleting 10" << std::endl;
    bt = bt->delete_key(10);

    print_tree(bt);
}