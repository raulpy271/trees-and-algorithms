
#ifndef BTREE_H_
#define BTREE_H_

template <typename T, unsigned int MinDegree> class BTree {
public:
    bool leaf;
    unsigned int used_keys;
    T keys[2 * MinDegree - 1] = {T()};
    BTree<T, MinDegree>* children[2 * MinDegree] = {nullptr};

    BTree();
    void splitChild(unsigned int child_index);
};

#endif // BTREE_H_ 
