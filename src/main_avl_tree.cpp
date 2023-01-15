
#include <iostream>

#include "avltree.h"

int main () {
    Tree<int>* t1 = new Tree<int>(1);

    std::cout << insert(t1, 20)  << std::endl;
    std::cout << insert(t1, 10)  << std::endl;
    std::cout << insert(t1, 10)  << std::endl;
    std::cout << insert(t1, -1)  << std::endl;

    t1->iterate([=] (Tree<int>* node, int index) {
        std::cout << node->info << " ";
    });

    t1->delete_tree();
    return 0;
}