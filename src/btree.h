
#ifndef BTREE_H_
#define BTREE_H_

template <typename T, unsigned int MinDegree> class BTree {
public:
    unsigned int min_degree;
    bool leaf;
    unsigned int used_children;
    T keys[2 * MinDegree - 1] = {T()};
    BTree<T, MinDegree>* children[2 * MinDegree] = {nullptr};

    BTree();
};

#endif // BTREE_H_ 
