
#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "tree.h"

template <typename T> bool insert(Tree<T>* tree, T value);
template <typename T> Tree<T>* insert_without_rebalance(Tree<T>* tree, T info);
template <typename T> void rotate_left(Tree<T>** tree);
template <typename T> void rotate_right(Tree<T>** tree);
template <typename T> void rotate_right_left(Tree<T>** tree);

#endif // AVLTREE_H_