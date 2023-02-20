
#include "btree.h"

template <typename T, unsigned int MinDegree> BTree<T, MinDegree>::BTree() {
    leaf = true;
    used_keys = 0;
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::splitChild(unsigned int child_index) {
    BTree<T, MinDegree>* new_node = new BTree<T, MinDegree>();
    BTree<T, MinDegree>* child = this->children[child_index];
    new_node->leaf = child->leaf;
    new_node->used_keys = MinDegree - 1;
    for (int j = 0; j < (MinDegree - 1); j++) {
        new_node->keys[j] = child->keys[MinDegree + j];
    }
    if (!child->leaf) {
        for (int j = 0; j < MinDegree; j++) {
            new_node->children[j] = child->children[MinDegree + j];
        }
    }
    child->used_keys = MinDegree - 1;
    for (int j = used_keys; j > child_index; j--) {
        children[j + 1] = children[j];
    }
    children[child_index + 1] = new_node;
    for (int j = used_keys - 1; j > (child_index - 1); j--) {
        keys[j + 1] = keys[j];
    }
    keys[child_index] = child->keys[MinDegree - 1];
    used_keys++;
}

template class BTree<int, 10>;