#include "utils.h"
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <queue>



using namespace std;

int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}


vector<vector<int>> MakeAdjMatrix(const std::string& filename, int vertices) { 
    vector<vector<int>> adj_matrix(vertices,vector<int>(vertices, 0)); //adj  matrix
    string line,word;

    fstream file(filename, ios::in);
    if(file.is_open()) {
        while(getline(file, line)) {
            vector<string> items;
            SplitString(line, ',', items);
            if(items[0] == "" || items[1] == "" || items[2] == "") continue;
            try {
            int idx1 = stoi(items[0]);
            int idx2 = stoi(items[1]);
            if (idx1 >= vertices || idx2 >= vertices) continue;
            int weight = stoi(items[2]);
            adj_matrix[idx1][idx2] = weight;
            adj_matrix[idx2][idx1] = weight;
            } catch (const std::invalid_argument& e) {
                continue;
            }
        }
    }
    return adj_matrix;
}


// int main()
// {
    // Create an adjacency matrix for a graph with 4 nodes
    // vector<vector<int>> adjacencyMatrix = {
    //     { 0, 4, 0, 0 },
    //     { 4, 0, 8, 0 },
    //     { 0, 8, 0, 7 },
    //     { 0, 0, 7, 0 }
    // };

    // auto adjacencyMatrix = MakeAdjMatrix("lodu.csv", 6);
    // Get the distances from node 0 to each node in the graph
    // vector<int> distances = dijkstra(adjacencyMatrix, 0);
    // for (int distance : distances) {
    //     cout << distance << " ";
    //     cout << endl;
    // }
// }









