
#include <iostream>

#include "freq.h"
#include "tree.h"

template <typename T> Tree<T>::Tree(T info) {
    father = nullptr;
    left = nullptr;
    right = nullptr;
    this->info = info;
}

template <typename T> void Tree<T>::delete_tree() {
    if (left != nullptr)
        left->delete_tree();
    if (right != nullptr)
        right->delete_tree();
    delete this;
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

template <typename T> void Tree<T>::iterate(std::function<void(Tree<T>*, int)> func) {
    int index = 0;
    iterate_recursive(func, this, &index);
}

template <typename T> void Tree<T>::iterate_recursive(
        std::function<void(Tree<T>*, int)> func,
        Tree<T>* subtree,
        int* index) {
    if (subtree->left != nullptr)
        iterate_recursive(func, subtree->left, index);
    func(subtree, *index);
    *index = (*index) + 1;
    if (subtree->right != nullptr)
        iterate_recursive(func, subtree->right, index);
}

template <typename T> void print_leaf(Tree<T>* t) {
    if (t != nullptr)
        std::cout << "( " + std::to_string(t->info) + " ) -> ";
    else
        std::cout << "end" << std::endl;
}

template <typename T> std::string tree_repr(Tree<T>* t, std::function<std::string(T)> to_str, int current_depth) {
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
        repr += to_str(t->info) + "\n";
        repr += tree_repr(t->left, to_str, current_depth + 1);
        repr += tree_repr(t->right, to_str, current_depth + 1);
    } else {
        repr += "null\n";
    }
    return repr;
}

template <typename T> void insert_in_frequency_tree(Tree<Freq<T>>* tree, T value) {
    Tree<Freq<T>>* subtree = tree;
    while (true) {
        if (value == subtree->info.value) {
            subtree->info.inc();
            break;
        }
        if (value > subtree->info.value) {
            if (subtree->right != nullptr) {
                subtree = subtree->right;
            } else {
                subtree->right = new Tree<Freq<T>>(
                    Freq<T>(value)
                );
                break;
            }
        }
        if (value < subtree->info.value) {
            if (subtree->left != nullptr) {
                subtree = subtree->left;
            } else {
                subtree->left = new Tree<Freq<T>>(
                    Freq<T>(value)
                );
                break;
            }
        }
    }
}

template <typename T> Tree<Freq<T>>* create_frequency_tree(T* arr, size_t size) {
    Tree<Freq<T>>* root = new Tree<Freq<T>>(Freq<T>(arr[0]));
    for (int i = 1; i < size; i++) {
        insert_in_frequency_tree<T>(root, arr[i]);
    }
    return root;
}


// When using template classes/function with implementation separated from header file 
// is needed to explicitly instantiate the template.
// reference: https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file 
template class Tree<Freq<char>>;
template std::string tree_repr<Freq<char>> (Tree<Freq<char>>*, std::function<std::string(Freq<char>)>, int);
template void insert_in_frequency_tree<char> (Tree<Freq<char>>*, char);
template Tree<Freq<char>>* create_frequency_tree<char> (char*, size_t);