#pragma once
#include <utility>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <fstream>
using std::vector;
using std::cout; using std::endl;
vector<vector<int>> MakeAdjMatrix(const std::string& filename, int vertices);
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);

