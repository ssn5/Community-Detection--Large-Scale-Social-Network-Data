CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/main.cpp ./src/BFS.cpp ./src/dijkstra.cpp ./src/gv.cpp ./src/utils.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: obj/catch.o tests/test_gv.cc tests/test_dijkstra.cc tests/test_bfs.cc src/BFS.cc src/dijkstra.cc src/gv.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@	

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -f bin/*