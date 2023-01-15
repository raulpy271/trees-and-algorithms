src = src/freq.* src/pqueue.* src/llist.* src/tree.* src/huffman_coding.* src/avltree.*
obj = build/freq.o build/pqueue.o build/llist.o build/tree.o build/huffman_coding.o build/avltree.o

$(obj): $(src)
	$(CXX) -c src/freq.cpp -o build/freq.o
	$(CXX) -c src/pqueue.cpp -o build/pqueue.o
	$(CXX) -c src/llist.cpp -o build/llist.o
	$(CXX) -c src/tree.cpp -o build/tree.o
	$(CXX) -c src/huffman_coding.cpp -o build/huffman_coding.o
	$(CXX) -c src/avltree.cpp -o build/avltree.o

build/main_huffman_coding.o: src/main_huffman_coding.cpp
	$(CXX) -c src/main_huffman_coding.cpp -o build/main_huffman_coding.o

build/main_avl_tree.o: src/main_avl_tree.cpp
	$(CXX) -c src/main_avl_tree.cpp -o build/main_avl_tree.o

main-huffman-coding: $(obj) build/main_huffman_coding.o
	$(CXX) $(obj) build/main_huffman_coding.o -o build/main

main-avl-tree: $(obj) build/main_avl_tree.o
	$(CXX) $(obj) build/main_avl_tree.o -o build/main

run-huffman-coding: main-huffman-coding
	chmod +x build/main
	./build/main

run-avl-tree: main-avl-tree
	chmod +x build/main
	./build/main

clean:
	rm -r build/*
