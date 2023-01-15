
#include <iostream>

#include "avltree.h"

int main () {
    AVLTree<int> t1(1);
    AVLTree<int> t2(2);
    AVLTree<int> t3(3);

    t1.set_left(&t2);
    t1.set_right(&t3);

    t1.iterate_leafs([=] (Tree<int>* node, int index) {
        std::cout << "info: " << node->info << std::endl;
    });

    return 0;
}