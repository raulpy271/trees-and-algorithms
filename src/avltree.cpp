
#include "avltree.h"

template <typename T> bool insert(Tree<T>* tree, T value) {
    Tree<T>* node = insert_without_rebalance(tree, value);
    return node != nullptr;
}

template <typename T> Tree<T>* insert_without_rebalance(Tree<T>* tree, T info) {
    Tree<T>* subnode = tree;
    Tree<T>* subnode_father = tree->father;
    while (subnode != nullptr && subnode->info != info) {
        subnode_father = subnode;
        if (info < subnode->info) {
            subnode = subnode->left;
        } else {
            subnode = subnode->right;
        }
    }
    if (subnode != nullptr) {
        // The element already exists in the tree
        return nullptr;
    } else {
        Tree<T>* node = new Tree<T>(info);
        if (info < subnode_father->info) {
            subnode_father->set_left(node);
        } else {
            subnode_father->set_right(node);
        }
        return node;
    }
}

template Tree<int>* insert_without_rebalance<int> (Tree<int>*, int);
template bool insert<int> (Tree<int>* tree, int value);