
#include <iostream>

#include "freq.h"
#include "tree.h"
#include "huffman_coding.h"

int main () {
    Tree<Freq<char>>* tree;
    HuffmanTree* huffman_tree;
    std::string text;

    std::cout << "Type the message to encode: ";
    std::cin >> text;

    int text_size = text.length();
    char text_arr[text_size];
    text.copy(text_arr, text_size, 0);

    tree = create_frequency_tree<char>(text_arr, text_size);
    int nodes_size = tree->count_nodes();

    char chars[nodes_size];
    int frequencies[nodes_size];
    set_values_and_frequencies<char>(*tree, chars, frequencies);
    huffman_tree = create_huffman_tree(chars, frequencies, nodes_size);

    HuffmanCodeArray huffman_code_arr = create_huffman_coding(huffman_tree, nodes_size);
    sort_huffman_code(huffman_tree, huffman_code_arr, chars, nodes_size);

    std::string text_coded = encode_text(huffman_code_arr, text_arr, chars, nodes_size, text_size);
    std::cout << "codded: \"" << text_coded << "\"" << std::endl;

    std::string text_decoded = decode_text(huffman_tree, text_coded);
    std::cout << "decodded: \"" << text_decoded << "\"" << std::endl;

    tree->delete_tree();
    huffman_tree->delete_tree();
    delete_array_of_linked_list<bool>(huffman_code_arr, nodes_size);
    delete[] huffman_code_arr;

    return 0;
}