
#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "tree.h"

template <typename T> class AVLTree: public Tree<T> {
public:
    AVLTree(T info);

    bool insert(T info);
};

#endif // AVLTREE_H_