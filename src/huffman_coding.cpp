
#include "huffman_coding.h"

template <typename T> Tree<Freq<T>>* create_huffman_tree(T* values, int* frequencies, size_t size) {
    Tree<Freq<T>>* node = new Tree<Freq<T>>(
        Freq<T>(values[0], frequencies[0])
    );
    AscedingPQueue<Tree<Freq<T>>*>* nodes = new AscedingPQueue<Tree<Freq<T>>*>(node, frequencies[0]);
    for (int i = 1; i < size; i++) {
        node = new Tree<Freq<T>>(
            Freq<T>(values[i], frequencies[i])
        );
        pq_insert<Tree<Freq<T>>*>(&nodes, node, frequencies[i]);
    }
    Tree<Freq<T>>* left_node;
    Tree<Freq<T>>* right_node;
    int freq;
    while (nodes->count_nodes() > 1) {
        left_node = pq_pop_min<Tree<Freq<T>>*>(&nodes);
        right_node = pq_pop_min<Tree<Freq<T>>*>(&nodes);
        freq = left_node->info.freq + right_node->info.freq;
        node = new Tree<Freq<T>>(Freq<T>((T) NULL, freq));
        node->left = left_node;
        node->right = right_node;
        pq_insert<Tree<Freq<T>>*>(&nodes, node, freq);
    }
    node = pq_pop_min<Tree<Freq<T>>*>(&nodes);
    return node;
}

template class AscedingPQueue<Tree<Freq<char>>*>;
template Tree<Freq<char>>* create_huffman_tree<char> (char*, int*, size_t);