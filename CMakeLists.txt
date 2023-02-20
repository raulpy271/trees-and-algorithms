
cmake_minimum_required(VERSION 3.15)

project(trees-and-algorithms)

add_library(tree-and-algorithms
    src/avltree.cpp
    src/llist.cpp
    src/pqueue.cpp
    src/freq.cpp
    src/tree.cpp
    src/huffman_coding.cpp
    src/btree.cpp
)

add_executable(main_huffman src/main_huffman_coding.cpp)
add_executable(main_avl_tree src/main_avl_tree.cpp)
add_executable(main_btree src/main_btree.cpp)

target_link_libraries(main_huffman PRIVATE tree-and-algorithms)
target_link_libraries(main_avl_tree PRIVATE tree-and-algorithms)
target_link_libraries(main_btree PRIVATE tree-and-algorithms)

