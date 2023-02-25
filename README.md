[![License: MIT](https://img.shields.io/badge/License-MIT-success.svg)](https://opensource.org/licenses/MIT)
[![My followers](https://img.shields.io/github/followers/raulpy271?style=social)](https://github.com/raulpy271)

# Tree and Algorithms

This repository has some implementation of algorithms that use trees as a data structure.

See a list of implemented algorithms:

 - Huffman Coding
 - BTree

# How to setup

There is no dependency on other libraries besides the standard c++ library, so you only need a compiler and cmake to run and build the code.

Installing a compiler and cmake:

```sh
apt-get update
apt-get -y install g++ cmake 
```

After that, you can compile/run using the Makefile, as following:

```sh
# To run huffman coding example: src/main_huffman_coding.cpp
make run-huffman-coding

# To run btree example: src/main_btree.cpp
make run-btree 
```

# References

See the list of useful resources:

- [Huffman Coding](https://en.wikipedia.org/wiki/Huffman_coding)
- [BTree](https://en.wikipedia.org/wiki/B-tree)
