#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "gv.h"
//#include "tests_util.h"

TEST_CASE("Girvan Newman easy", "[weight=5]") {
        std::vector<std::vector<int>> result = { {0, 0, 1, 0, 0, 0},
                                            {0, 0, 1, 0, 0, 0},
                                            {1, 1, 0, 1, 0, 0},
                                            {0, 0, 1, 0, 0, 1},
                                            {0, 0, 0, 0, 0, 1},
                                            {0, 0, 0, 1, 1, 0}};

    std::vector<std::vector<int>> graph = { {0, 1, 1, 0, 0, 0},
                                            {1, 0, 1, 0, 0, 0},
                                            {1, 1, 0, 1, 0, 0},
                                            {0, 0, 1, 0, 1, 1},
                                            {0, 0, 0, 1, 0, 1},
                                            {0, 0, 0, 1, 1, 0}};
    auto gv = girvanNewman(graph);

    REQUIRE(gv == result);

}

TEST_CASE("Girvan Newman hard", "[weight=5]") {
    std::vector<std::vector<int>> graph ={  {0,0,1,1,1,0,0,0,0,0},
                                            {0,0,1,1,1,1,0,0,0,0},
                                            {1,1,0,1,1,1,0,0,0,0},
                                            {1,1,1,0,1,1,1,0,0,0},
                                            {1,1,1,1,0,1,1,1,0,0},
                                            {0,1,1,1,1,0,1,1,1,0},
                                            {0,0,0,1,1,1,0,1,1,1},
                                            {0,0,0,0,1,1,1,0,1,1},
                                            {0,0,0,0,0,1,1,1,0,1},
                                            {0,0,0,0,0,0,1,1,1,0}};

    std::vector<std::vector<int>> result = {{0,0,0,1,1,0,0,0,0,0},
                                            {0,0,0,1,1,1,0,0,0,0},
                                            {0,0,0,1,1,1,0,0,0,0},
                                            {1,1,1,0,0,0,1,0,0,0},
                                            {1,1,1,0,0,0,1,1,0,0},
                                            {0,1,1,0,0,0,1,1,0,0},
                                            {0,0,0,1,1,1,0,0,1,1},
                                            {0,0,0,0,1,1,0,0,1,1},
                                            {0,0,0,0,0,0,1,1,0,0},
                                            {0,0,0,0,0,0,1,1,0,0}};
    auto gv = girvanNewman(graph);

    REQUIRE(gv == result);

}

