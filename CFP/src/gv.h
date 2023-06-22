#pragma once
#include <iostream>
#include <vector>

using namespace std;


int findMaxEdge(vector<vector<int> > &adjMatrix);
void removeMaxEdge(vector<vector<int> > &adjMatrix, int maxEdgeIndex);
vector<vector<int> > girvanNewman(vector<vector<int> > &adjMatrix);