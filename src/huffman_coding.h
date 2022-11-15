
#ifndef HUFFMAN_CODING_H_
#define HUFFMAN_CODING_H_

#include "freq.h"
#include "pqueue.h"
#include "llist.h"
#include "tree.h"

typedef Tree<Freq<char>> HuffmanTree;
typedef LinkedList<bool>* HuffmanCode;
typedef LinkedList<bool>** HuffmanCodeArray;

template <typename T> Tree<Freq<T>>* create_huffman_tree(T* values, int* frequencies, size_t size);

HuffmanCodeArray create_huffman_coding(HuffmanTree* tree, size_t leaf_size);

void sort_huffman_code(HuffmanTree* tree, HuffmanCodeArray huffman_code, char* ordered_char, size_t size);

#endif // HUFFMAN_CODING_H_