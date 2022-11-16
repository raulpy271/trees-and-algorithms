
#include "huffman_coding.h"

HuffmanTree* create_huffman_tree(char* values, int* frequencies, size_t size) {
    HuffmanTree* node = new HuffmanTree(
        Freq<char>(values[0], frequencies[0])
    );
    AscedingPQueue<HuffmanTree*>* nodes = new AscedingPQueue<HuffmanTree*>(node, frequencies[0]);
    for (int i = 1; i < size; i++) {
        node = new HuffmanTree(
            Freq<char>(values[i], frequencies[i])
        );
        pq_insert<HuffmanTree*>(&nodes, node, frequencies[i]);
    }
    HuffmanTree* left_node;
    HuffmanTree* right_node;
    int freq;
    while (nodes->count_nodes() > 1) {
        left_node = pq_pop_min<HuffmanTree*>(&nodes);
        right_node = pq_pop_min<HuffmanTree*>(&nodes);
        freq = left_node->info.freq + right_node->info.freq;
        node = new HuffmanTree(Freq<char>('\0', freq));
        node->set_left(left_node);
        node->set_right(right_node);
        pq_insert<HuffmanTree*>(&nodes, node, freq);
    }
    node = pq_pop_min<HuffmanTree*>(&nodes);
    return node;
}

HuffmanCodeArray create_huffman_coding(HuffmanTree* tree, size_t leaf_size) {
    HuffmanCodeArray code_arr = new HuffmanCode[leaf_size];
    tree->iterate_leafs([=] (HuffmanTree* leaf, int index) {
        HuffmanCode code = nullptr;
        HuffmanTree* node = leaf;
        while (node != tree) {
            if (node->father->left == node) {
                list_insert_start<bool>(&code, false);
            } else {
                list_insert_start<bool>(&code, true);
            }
            node = node->father;
        }
        code_arr[index] = code;
    });
    return code_arr;
}

void sort_huffman_code(HuffmanTree* tree, HuffmanCodeArray huffman_code, char* ordered_char, size_t size) {
    HuffmanCodeArray ordered_code = new HuffmanCode[size];
    tree->iterate_leafs([=] (HuffmanTree* leaf, int code_index) {
        char char_to_find = leaf->info.value;
        HuffmanCode temp_code = nullptr;
        for (int new_index = 0; new_index < size; new_index++) {
            if (char_to_find == ordered_char[new_index]) {
                ordered_code[new_index] = huffman_code[code_index];
                return;
            }
        }
    });
    for (int i = 0; i < size; i++) {
        huffman_code[i] = ordered_code[i];
    }
    delete[] ordered_code;
}

template class AscedingPQueue<HuffmanTree*>;