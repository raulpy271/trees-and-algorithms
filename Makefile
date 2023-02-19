CMAKE_BUILD=build

clean:
	rm -r $(CMAKE_BUILD)/*

generate-buildsystem:
	cd $(CMAKE_BUILD) && cmake ..

build-cmake:
	cmake --build $(CMAKE_BUILD)

run-huffman-coding: build-cmake
	./$(CMAKE_BUILD)/main_huffman

run-avl-tree: build-cmake
	./$(CMAKE_BUILD)/main_avl_tree
