
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
    if (tree->is_leaf()) {
        // If the tree has a single node, we encode it with a constant value, false(zero) in the case.
        HuffmanCode code = nullptr;
        list_insert_start<bool>(&code, false);
        code_arr[0] = code;
        return code_arr;
    }
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

HuffmanCode encode_char(HuffmanCodeArray codes, char to_encode, char* chars, size_t chars_size) {
    char c;
    for (int i = 0; i < chars_size; i++) {
        c = chars[i];
        if (to_encode == c) {
            return codes[i];
        }
    }
    return nullptr;
}

std::string encode_text(HuffmanCodeArray codes, char* text, char* chars, size_t chars_size, size_t text_size) {
    std::string encoded = "";
    char to_encode;
    for (int i = 0; i < text_size; i++) {
        to_encode = text[i];
        encoded += bool_list_to_string(encode_char(codes, to_encode, chars, chars_size));
    }
    return encoded;
}

std::string decode_text(HuffmanTree* tree, std::string coded_msg) {
    std:: string decoded = "";
    size_t size = coded_msg.length();
    char to_decode;
    HuffmanTree* subtree = tree;
    int i = 0;
    if (tree->is_leaf()) {
        // if the tree has a single node, each binary digit represents a char, which is the leaf char.
        for (; i < size; i++) {
            decoded += tree->info.value;
        }
        return decoded;
    }
    while (i < size) {
        if (subtree->is_leaf()) {
            decoded += subtree->info.value;
            subtree = tree;
            continue;
        }
        else {
            to_decode = coded_msg[i];
            if (to_decode == '0') {
                subtree = subtree->left;
            } else {
                subtree = subtree->right;
            }
            i++;
        }
    }
    if (subtree->is_leaf())
        decoded += subtree->info.value;
    return decoded;
}

void sort_huffman_code(HuffmanTree* tree, HuffmanCodeArray huffman_code, char* ordered_char, size_t size) {
    HuffmanCodeArray ordered_code = new HuffmanCode[size];
    tree->iterate_leafs([=] (HuffmanTree* leaf, int code_index) {
        char char_to_find = leaf->info.value;
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