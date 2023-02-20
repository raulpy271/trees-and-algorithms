
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

template <typename T, unsigned int MinDegree>
std::string BTree<T, MinDegree>::tree_repr(std::function<std::string(T)> to_str, unsigned int depth) {
    std::string repr = "";
    std::string ident = "";
    for (int i = depth; i > 0; i--) {
        ident += "    ";
    }
    if (leaf) {
        for (int i = 0; i < used_keys; i++) {
            repr += (ident + "* " + to_str(keys[i]) + "\n");
        }
    } else {
        for (int i = 0; i < used_keys; i++) {
            repr += children[i]->tree_repr(to_str, depth + 1);
            repr += (ident + "* " + to_str(keys[i]) + "\n");
        }
        repr += children[used_keys]->tree_repr(to_str, depth + 1);
    }
    return repr;
}

template class BTree<int, 10>;