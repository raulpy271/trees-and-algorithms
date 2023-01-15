
#include "avltree.h"

template <typename T> AVLTree<T>::AVLTree(T value) : Tree<T>(value) {}

template <typename T> bool AVLTree<T>::insert(T value) {
    return true;
}

template class AVLTree<int>;