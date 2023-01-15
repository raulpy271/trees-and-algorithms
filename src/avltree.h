
#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "tree.h"

template <typename T> bool insert(Tree<T>* tree, T value);
template <typename T> Tree<T>* insert_without_rebalance(Tree<T>* tree, T info);

#endif // AVLTREE_H_