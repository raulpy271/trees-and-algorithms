
#include <iostream>

#include "tree.h"

template <typename T> Tree<T>::Tree(T info) {
    father = nullptr;
    left = nullptr;
    right = nullptr;
    this->info = info;
}

template <typename T> void Tree<T>::set_left(Tree<T>* left) {
    if (left != nullptr) {
        this->left = left;
        left->father = this;
    }
}

template <typename T> void Tree<T>::set_right(Tree<T>* right) {
    if (right != nullptr) {
        this->right = right;
        right->father = this;
    }
}

template <typename T> void Tree<T>::iterate(std::function<void(Tree<T>*)> func) {
    iterate_recursive(func, this);
}

template <typename T> void Tree<T>::iterate_recursive(
        std::function<void(Tree<T>*)> func,
        Tree<T>* subtree) {
    if (subtree->left != nullptr)
        iterate_recursive(func, subtree->left);
    func(subtree);
    if (subtree->right != nullptr)
        iterate_recursive(func, subtree->right);
}

template <typename T> void print_leaf(Tree<T>* t) {
    if (t != nullptr)
        std::cout << "( " + std::to_string(t->info) + " ) -> ";
    else
        std::cout << "end" << std::endl;
}

template <typename T> std::string tree_repr(Tree<T>* t, int current_depth) {
    std::string repr = "";
    for (int i = current_depth; i > 0; i--) {
        repr += "   ";
    }
    if (current_depth % 2 == 0) {
        repr += "* ";
    } else {
        repr += "+ ";
    }
    if (t != nullptr) {
        repr += std::to_string(t->info) + "\n";
        repr += tree_repr(t->left, current_depth + 1);
        repr += tree_repr(t->right, current_depth + 1);
    } else {
        repr += "null\n";
    }
    return repr;
}
