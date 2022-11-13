src = src/freq.* src/pqueue.* src/tree.* src/main.*
obj = build/freq.o build/pqueue.o build/tree.o build/main.o

$(obj): $(src)
	$(CXX) -c src/freq.cpp -o build/freq.o
	$(CXX) -c src/pqueue.cpp -o build/pqueue.o
	$(CXX) -c src/tree.cpp -o build/tree.o
	$(CXX) -c src/main.cpp -o build/main.o

main: $(obj)
	$(CXX) $(obj) -o build/main

run: main
	chmod +x build/main
	./build/main

clean:
	rm -r build/*
