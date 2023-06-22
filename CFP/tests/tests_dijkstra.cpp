#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "dijkstra.h"
//#include "tests_util.h"

TEST_CASE("Dijkstra easy", "[weight=5]") {
     vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                {2, 0, 3, 8, 5},
                                {0, 3, 0, 0, 7},
                                {6, 8, 0, 0, 9},
                                {0, 5, 7, 9, 0}};

    auto dijkstra_ = dijkstra(graph,0);
    std::vector<int> result = {0,2,5,6,7};
    REQUIRE(dijkstra_ == result);

}

TEST_CASE("Dijkstra hard", "[weight=5]") {
     vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                  { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                  { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                  { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                  { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                  { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                  { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                  { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                  { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    auto dijkstra_ = dijkstra(graph,0);
    std::vector<int> result = {0,4,12,19,21,11,9,8,14};
    REQUIRE(dijkstra_ == result);

}

