
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
    BTree<T, MinDegree>* insert(T key);
    BTree<T, MinDegree>* delete_key(T key);
    bool search_key(T key);
    std::string tree_repr(std::function<std::string(T)> to_str, unsigned int depth = 0);

private:
    void insert_in_nonfull(T key);
    void delete_in_nonmin(T key);
    void split_child(unsigned int child_index);
    void move_from_right_to_child(unsigned int child_index);
    void move_from_left_to_child(unsigned int child_index);
    void merge_child(unsigned int child_index);
    bool has_min_keys();
};

#endif // BTREE_H_ 
