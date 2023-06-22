#include <iostream>
#include <vector>
#include "gv.h"
using namespace std;

// function to find the edge with the highest betweenness centrality
int findMaxEdge(vector<vector<int> > &adjMatrix)
{
    int maxEdge = 0;
    int maxEdgeIndex = 0;
    int n = adjMatrix.size();   // number of vertices
    
    // loop through all edges
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            // check if the edge exists
            if (adjMatrix[i][j] != 0)
            {
                // compute the betweenness centrality of the edge
                int bc = 0;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        if (adjMatrix[i][k] != 0 && adjMatrix[k][j] != 0 )
                        {
                            bc++;
                        }
                    }
                }
                
                // update maxEdge and maxEdgeIndex
                if (bc > maxEdge)
                {
                    maxEdge = bc;
                    maxEdgeIndex = i * n + j;
                }
            }
        }
    }
    
    // return the index of the edge with the highest betweenness centrality
    return maxEdgeIndex;
}

// function to remove the edge with the highest betweenness centrality
void removeMaxEdge(vector<vector<int> > &adjMatrix, int maxEdgeIndex)
{
    int n = adjMatrix.size();   // number of vertices
    
    // find the indices of the two vertices
    int vertex1 = maxEdgeIndex / n;
    int vertex2 = maxEdgeIndex % n;
    
    // set the corresponding matrix entry to 0
    adjMatrix[vertex1][vertex2] = 0;
    adjMatrix[vertex2][vertex1] = 0;
}

// Girvan-Newman algorithm
vector<vector<int> > girvanNewman(vector<vector<int> > &adjMatrix)
{
    // until there are no more edges
    while (true)
    {
        int maxEdgeIndex = findMaxEdge(adjMatrix);
        
        // check if there are no edges left
        if (maxEdgeIndex == 0)
            break;
        
        // remove the edge with the highest betweenness centrality
        removeMaxEdge(adjMatrix, maxEdgeIndex);
    }
    
    return adjMatrix;
}
