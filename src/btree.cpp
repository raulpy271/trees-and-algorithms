
#include "btree.h"

template <typename T, unsigned int MinDegree> BTree<T, MinDegree>::BTree() {
    min_degree = MinDegree;
    leaf = true;
    used_children = 0;
}

template class BTree<int, 10>;