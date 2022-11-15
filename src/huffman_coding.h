
#ifndef HUFFMAN_CODING_H_
#define HUFFMAN_CODING_H_

#include "freq.h"
#include "pqueue.h"
#include "tree.h"

template <typename T> Tree<Freq<T>>* create_huffman_tree(T* values, int* frequencies, size_t size);

#endif // HUFFMAN_CODING_H_