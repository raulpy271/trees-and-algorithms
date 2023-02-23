
#include "btree.h"
#include <iostream>

template <typename T, unsigned int MinDegree> BTree<T, MinDegree>::BTree() {
    leaf = true;
    used_keys = 0;
}

template <typename T, unsigned int MinDegree>
bool BTree<T, MinDegree>::search_key(T key) {
    int i;
    for (i = 0; (i < used_keys) && key > keys[i]; i++);
    if ((i < used_keys) && (key == keys[i])) {
        return true;
    }
    if (leaf) {
        return false;
    } else {
        return children[i]->search_key(key);
    }
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::split_child(unsigned int child_index) {
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
    for (int j = used_keys - 1; j > (((int)child_index) - 1); j--) {
        keys[j + 1] = keys[j];
    }
    keys[child_index] = child->keys[MinDegree - 1];
    used_keys++;
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::insert_in_nonfull(T key) {
    int i = used_keys - 1;
    if (leaf) {
        for (; (i >= 0) && (key < keys[i]); i--) {
            keys[i + 1] = keys[i];
        }
        keys[i + 1] = key;
        used_keys++;
    } else {
        for (; (i >= 0) && (key < keys[i]); i--);
        i++;
        if ((children[i]->used_keys) >= (2 * MinDegree - 1)) {
            split_child(i);
            if (key > keys[i]) {
                i++;
            }
        }
        children[i]->insert_in_nonfull(key);
    }
}

template <typename T, unsigned int MinDegree>
BTree<T, MinDegree>* BTree<T, MinDegree>::insert(T key) {
    BTree<T, MinDegree>* root = this;
    if (used_keys >= (2 * MinDegree - 1)) {
        root = new BTree<T, MinDegree>();
        root->leaf = false;
        root->children[0] = this;
        root->split_child(0);
    }
    root->insert_in_nonfull(key);
    return root;
}

template <typename T, unsigned int MinDegree>
BTree<T, MinDegree>* BTree<T, MinDegree>::delete_key(T key) {
    if ((used_keys == 1) && children[0]->has_min_keys() && children[1]->has_min_keys()) {
        std::cout << "O caso onde a raiz possui apenas dois filhos com quantidade mínima de chaves não foi implementado" << std::endl;
        throw 404;
    } else {
        delete_in_nonmin(key);
        return this;
    }
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::delete_in_nonmin(T key) {
    int i;
    for (i = 0; (i < used_keys) && key > keys[i]; i++);
    bool found_key = (i < used_keys) && (key == keys[i]);
    if (leaf) {
        if (found_key) {
            for (; i < (used_keys - 1); i++) {
                keys[i] = keys[i + 1];
            } 
            used_keys--;
        }
        return;
    }
    if (found_key) {
        if (children[i]->has_min_keys()) {
            if (children[i + 1]->has_min_keys()) {
                std::cout << "O caso onde a chave foi encontrada e nó interno e ambos os filhos possuem t - 1 chaves não foi implementado" << std::endl;
                throw 404;
            } else {
                replace_key_from_right(i);
            }
        } else {
            replace_key_from_left(i);
        }
    } else {
        if (children[i]->has_min_keys()) {
            if (i == 0) {
                if (children[i + 1]->has_min_keys()) {
                    merge_child(i);
                } else {
                    move_from_right_to_child(i);
                }
            } else {
                if (i == used_keys) {
                    if (children[i - 1]->has_min_keys()) {
                        i--;
                        merge_child(i);
                    } else {
                        move_from_left_to_child(i);
                    }

                } else {
                    if (!(children[i + 1]->has_min_keys())) {
                        move_from_right_to_child(i);
                    } else {
                        if (!(children[i - 1]->has_min_keys())) {
                            move_from_left_to_child(i);
                        } else {
                            merge_child(i);
                        }
                    }
                }
            }
        }
        children[i]->delete_in_nonmin(key);
    }
}

template <typename T, unsigned int MinDegree>
std::string BTree<T, MinDegree>::tree_repr(std::function<std::string(T)> to_str, unsigned int depth) {
    if (!used_keys) {
        return "empty tree\n";
    }
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

template <typename T, unsigned int MinDegree>
bool BTree<T, MinDegree>::has_min_keys() {
    return used_keys == (MinDegree - 1);
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::move_from_right_to_child(unsigned int child_index) {
    BTree<T, MinDegree>* child = children[child_index];
    BTree<T, MinDegree>* right = children[child_index + 1];
    child->keys[child->used_keys] = keys[child_index];
    keys[child_index] = right->keys[0];
    if (!(child->leaf)) {
        child->children[(child->used_keys) + 1] = right->children[0];
        for (int i = 1; i <= right->used_keys; i++) {
            right->children[i - 1] = right->children[i];
        }
    }
    child->used_keys++;
    for (int i = 1; i < right->used_keys; i++) {
        right->keys[i - 1] = right->keys[i];
    }
    right->used_keys--;
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::move_from_left_to_child(unsigned int child_index) {
    BTree<T, MinDegree>* child = children[child_index];
    BTree<T, MinDegree>* left = children[child_index - 1];
    for (int i = child->used_keys; i > 0; i--) {
        child->keys[i] = child->keys[i - 1];
    }
    child->keys[0] = keys[child_index - 1];
    keys[child_index - 1] = left->keys[left->used_keys - 1];
    if (!(child->leaf)) {
        for (int i = child->used_keys; i >= 0; i--) {
            child->children[i + 1] = child->children[i];
        }
        child->children[0] = left->children[left->used_keys];
    }
    child->used_keys++;
    left->used_keys--;
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::replace_key_from_left(unsigned int key_index) {
    BTree<T, MinDegree>* child = children[key_index];
    BTree<T, MinDegree>* child_to_get_key;
    for (child_to_get_key = child;
        !(child_to_get_key->leaf);
        child_to_get_key = child_to_get_key->children[child_to_get_key->used_keys]
    );
    T new_key = child_to_get_key->keys[child_to_get_key->used_keys - 1];
    child_to_get_key->keys[child_to_get_key->used_keys - 1] = keys[key_index];
    child->delete_in_nonmin(keys[key_index]);
    keys[key_index] = new_key;
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::replace_key_from_right(unsigned int key_index) {
    BTree<T, MinDegree>* child = children[key_index + 1];
    BTree<T, MinDegree>* child_to_get_key;
    for (child_to_get_key = child;
        !(child_to_get_key->leaf);
        child_to_get_key = child_to_get_key->children[0]
    );
    T new_key = child_to_get_key->keys[0];
    child_to_get_key->keys[0] = keys[key_index];
    child->delete_in_nonmin(keys[key_index]);
    keys[key_index] = new_key;
}

template <typename T, unsigned int MinDegree>
void BTree<T, MinDegree>::merge_child(unsigned int child_index) {
    BTree<T, MinDegree>* child = children[child_index];
    BTree<T, MinDegree>* right = children[child_index + 1];
    child->keys[child->used_keys] = keys[child_index];
    for (int i = 0; i < right->used_keys; i++) {
        child->keys[child->used_keys + 1 + i] = right->keys[i];
    }
    if (!(child->leaf)) {
        for (int i = 0; i <= right->used_keys; i++) {
            child->children[child->used_keys + 1 + i] = right->children[i];
        }
    }
    for (int i = child_index; i < (used_keys - 1); i++) {
        keys[i] = keys[i + 1];
    }
    for (int i = child_index + 1; i < used_keys; i++) {
        children[i] = children[i + 1];
    }
    used_keys--;
    child->used_keys += right->used_keys + 1;
    delete right;
}

template class BTree<int, 10>;
template class BTree<int, 3>;