
#ifndef BTREE_H_
#define BTREE_H_

#include <string>
#include <functional>


template <typename T, unsigned int MinDegree> class BTree {
public:
    bool leaf;
    unsigned int used_keys;
    T keys[2 * MinDegree - 1] = {T()};
    BTree<T, MinDegree>* children[2 * MinDegree] = {nullptr};

    BTree();
    void split_child(unsigned int child_index);
    BTree<T, MinDegree>* insert(T key);
    void insert_in_nonfull(T key);
    bool search_key(T key);
    std::string tree_repr(std::function<std::string(T)> to_str, unsigned int depth = 0);
};

#endif // BTREE_H_ 
