
#include "btree.h"

#include <iostream>

void exemplo_insercao() {
    BTree<int, 3>* bt = new BTree<int, 3>();
    for (int i = 8; i > 0; i--) {
        std::cout << "inserindo " << i << std::endl;
        bt = bt->insert(i);
        std::cout << "resutado: " << std::endl;
        std::cout << bt->tree_repr([=] (int key) {return std::to_string(key);});
        std::cout << "\n";
    }
}

void exemplo_remocao() {
    int to_remove = 3;
    BTree<int, 3>* bt = new BTree<int, 3>();
    for (int i = 33; i > 0; i--) {
        bt = bt->insert(i);
    }
    std::cout << "arvore original: " << std::endl;
    std::cout << bt->tree_repr([=] (int key) {return std::to_string(key);});

    std::cout << "\nRemovendo: " << to_remove << std::endl;

    bt = bt->delete_key(to_remove);

    std::cout << bt->tree_repr([=] (int key) {return std::to_string(key);});
}

int main() {
    //exemplo_insercao();
    exemplo_remocao();
}