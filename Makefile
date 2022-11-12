src = src/tree.cpp src/main.cpp
obj = build/tree.o build/main.o

$(obj): $(src)
	$(CXX) -c src/tree.cpp -o build/tree.o
	$(CXX) -c src/main.cpp -o build/main.o

main: $(obj)
	$(CXX) $(obj) -o build/main

run: main
	chmod +x build/main
	./build/main

clean:
	rm -r build/*
