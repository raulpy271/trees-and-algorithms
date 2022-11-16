
#ifndef HUFFMAN_CODING_H_
#define HUFFMAN_CODING_H_

#include "freq.h"
#include "pqueue.h"
#include "llist.h"
#include "tree.h"

typedef Tree<Freq<char>> HuffmanTree;
typedef LinkedList<bool>* HuffmanCode;
typedef LinkedList<bool>** HuffmanCodeArray;

HuffmanTree* create_huffman_tree(char* values, int* frequencies, size_t size);

HuffmanCodeArray create_huffman_coding(HuffmanTree* tree, size_t leaf_size);

HuffmanCode encode_char(HuffmanCodeArray codes, char to_encode, char* chars, size_t chars_size);

std::string encode_text(HuffmanCodeArray codes, char* text, char* chars, size_t chars_size, size_t text_size);

std::string decode_text(HuffmanTree* tree, std::string coded_msg);

void sort_huffman_code(HuffmanTree* tree, HuffmanCodeArray huffman_code, char* ordered_char, size_t size);

#endif // HUFFMAN_CODING_H_