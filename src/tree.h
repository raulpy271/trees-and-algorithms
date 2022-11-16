
#ifndef TREE_H_
#define TREE_H_

#include <string>
#include <functional>

template <typename T> class Tree {
public:
    T info;
    Tree* left;
    Tree* right;
    Tree* father;

    Tree(T info);

    bool is_leaf();
    void set_left(Tree<T>* left);
    void set_right(Tree<T>* left);
    void iterate(std::function<void(Tree<T>*, int)> func);
    void iterate_leafs(std::function<void(Tree<T>*, int)> func);
    void delete_tree();
    size_t count_nodes();

private:
    void iterate_recursive(std::function<void(Tree<T>*, int)> func, Tree<T>* subtree, int* index);
    void iterate_recursive_leafs(std::function<void(Tree<T>*, int)> func, Tree<T>* subtree, int* leaf_index);
};

template <typename T> void print_leaf(Tree<T>* t);

template <typename T> std::string tree_repr(Tree<T>* t, std::function<std::string(T)> to_str, int current_depth = 0);

template <typename T> void insert_in_frequency_tree(Tree<Freq<T>>* tree, T value);

template <typename T> Tree<Freq<T>>* create_frequency_tree(T* arr, size_t size);

template <typename T> void set_values_and_frequencies(Tree<Freq<T>> tree, T* values, int* frequencies);

#endif // TREE_H_