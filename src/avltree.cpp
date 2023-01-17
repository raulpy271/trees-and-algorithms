
#include "avltree.h"

template <typename T> bool insert(Tree<T>* tree, T value) {
    Tree<T>* node = insert_without_rebalance(tree, value);
    return node != nullptr;
}

template <typename T> void rotate_left(Tree<T>** tree) {
    Tree<T>* right = (*tree)->right;
    Tree<T>* right_left = right->left;
    if (right_left != nullptr) {
        (*tree)->set_right(right_left);
    } else {
        (*tree)->right = nullptr;
    }
    right->father = (*tree)->father;
    right->set_left(*tree);
    *tree = right;
}

template <typename T> void rotate_right(Tree<T>** tree) {
    Tree<T>* left = (*tree)->left;
    Tree<T>* left_right = left->right;
    if (left_right != nullptr) {
        (*tree)->set_left(left_right);
    } else {
        (*tree)->left = nullptr;
    }
    left->father = (*tree)->father;
    left->set_right(*tree);
    *tree = left;
}

template <typename T> void rotate_right_left(Tree<T>** tree) {
    Tree<T>* right = (*tree)->right;
    Tree<T>* right_left = right->left;
    if (right_left->left != nullptr) {
        (*tree)->set_right(right_left->left);
    } else {
        (*tree)->right = nullptr;
    }
    if (right_left->right != nullptr) {
        right->set_left(right_left->right);
    } else {
        right->left = nullptr;
    }
    right_left->father = (*tree)->father;
    right_left->set_left(*tree);
    right_left->set_right(right);
    *tree = right_left;
}

template <typename T> void rotate_left_right(Tree<T>** tree) {
    Tree<T>* left = (*tree)->left;
    Tree<T>* left_right = left->right;
    if (left_right->left != nullptr) {
        left->set_right(left_right->left);
    } else {
        left->right = nullptr;
    }
    if (left_right->right != nullptr) {
        (*tree)->set_left(left_right->right);
    } else {
        (*tree)->left = nullptr;
    }
    left_right->father = (*tree)->father;
    left_right->set_left(left);
    left_right->set_right(*tree);
    *tree = left_right;
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
template void rotate_left<int> (Tree<int>**);
template void rotate_right<int> (Tree<int>**);
template void rotate_right_left<int> (Tree<int>**);
template void rotate_left_right<int> (Tree<int>**);
template bool insert<int> (Tree<int>*, int);