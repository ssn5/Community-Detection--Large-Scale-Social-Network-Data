#include "BFS.h"
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//#include "utils.h"

#include <iostream>
#include <queue>

std::vector<int> BFS(std::vector<std::vector<int>>&adjacencyMatrix,int start) {
  // create a queue for BFS
  std::queue<int> queue;

  // create a vector to keep track of visited nodes
  std::vector<bool> visited(100, false);

  // mark the current node as visited and enqueue it
  visited[start] = true;
  queue.push(start);
  std::vector<int> ret;
  // loop until the queue is empty
  while (!queue.empty()) {
    // dequeue the node at the front of the queue
    int node = queue.front();
    ret.push_back(node);
    //std::cout << node << " ";
    queue.pop();

    // check all the unvisited neighbors of the current node
    for (unsigned i = 0; i < adjacencyMatrix.size(); i++) {
      // cout << i << endl;
      if (adjacencyMatrix[node][i] != -1 && !visited[i]) {
        visited[i] = true;
        queue.push(i);
      }
    }
  }
  return ret;
}








