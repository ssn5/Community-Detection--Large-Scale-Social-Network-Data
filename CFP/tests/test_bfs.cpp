#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "BFS.h"

using namespace std;
//#include "tests_util.h"

TEST_CASE("BFS easy", "[weight=5]") {
        vector<vector<int>> graph =  {
        { 0, 1, 1, 0 },
        { 0, 0, 1, 0 },
        { 1, 0, 0, 1 },
        { 0, 0, 0, 1 }
    };

   std::vector<int> result = {0,1,2,3};
    auto bfs_ = BFS(graph,0);

    REQUIRE(bfs_ == result);
}

TEST_CASE("BFS hard", "[weight=5]") {
        vector<vector<int>> graph =   { 
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, 
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 
		{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 }, 
		{ 0, 0, 1, 1, 0, 1, 0, 0, 0, 0 }, 
		{ 0, 0, 0, 0, 1, 0, 1, 1, 0, 0 }, 
		{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 1 }, 
		{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 }, 
		{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 1 }, 
		{ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 } 
	}; 

   std::vector<int> result = {0,1,2,3,4,5,6,7,8,9};
    auto bfs_ = BFS(graph,0);

    REQUIRE(bfs_ == result);
}

