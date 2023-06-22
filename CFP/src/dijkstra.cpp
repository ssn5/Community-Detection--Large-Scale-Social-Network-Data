#include "dijkstra.h"
#include <limits.h>

// Define a pair to store the distance and the node index
typedef pair<int, int> pair_data;

// Function to implement Dijkstra's shortest path algorithm using an adjacency matrix
vector<int> dijkstra(vector<vector<int>>& adjacencyMatrix, int source)
{
    // Get the number of nodes in the graph
    int n = adjacencyMatrix.size();

    // Create a vector to store the distances from the source to each node
    vector<int> dist(n, INT_MAX);

   
    priority_queue<pair_data, vector<pair_data>, greater<pair_data>> pq;

    // Set the distance from the source to itself as zero
    dist[source] = 0;

 
    pq.push({ 0, source });

    while (!pq.empty())
    {
        // Get the pair at the top of the priority queue
        pair_data top = pq.top();

        // Extract the distance and the node index from the pair
        int distance = top.first;
        int node = top.second;

        // Pop the pair from the priority queue
        pq.pop();

        // If the distance is greater than the current distance, then skip it
        if (distance > dist[node])
            continue;

        // For each neighbor of the current node
        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            // If the current neighbor is not connected to the current node, then skip it
            if (adjacencyMatrix[node][neighbor] == 0)
                continue;

            // Calculate the new distance from the source to the current neighbor
            int newDist = distance + adjacencyMatrix[node][neighbor];

            // If the new distance is shorter than the current distance, then update it
            if (newDist < dist[neighbor])
            {
                dist[neighbor] = newDist;

                // Add the current neighbor to the priority queue
                pq.push({ newDist, neighbor });
            }
        }
    }
    // Return the vector of distances from the source to each node
    return dist;
}


