
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

    void set_left(Tree<T>* left);
    void set_right(Tree<T>* left);
    void iterate(std::function<void(Tree<T>*)> func);
    void delete_tree();

private:
    void iterate_recursive(std::function<void(Tree<T>*)> func, Tree<T>* subtree);
};

template <typename T> void print_leaf(Tree<T>* t);

template <typename T> std::string tree_repr(Tree<T>* t, std::function<std::string(T)> to_str, int current_depth = 0);

template <typename T> void insert_in_frequency_tree(Tree<Freq<T>>* tree, T value);

template <typename T> Tree<Freq<T>>* create_frequency_tree(T* arr, size_t size);

#endif // TREE_H_