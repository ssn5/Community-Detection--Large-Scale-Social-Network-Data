#include <iostream>
#include <gv.h>
#include <limits>
using namespace std;
#include "dijkstra.h"
#include "BFS.h"
#include "utils.h"

int main(){
    std::vector<std::vector<int>> vect_ ={  {0,0,1,1,1,0,0,0,0,0},
                                            {0,0,1,1,1,1,0,0,0,0},
                                            {1,1,0,1,1,1,0,0,0,0},
                                            {1,1,1,0,1,1,1,0,0,0},
                                            {1,1,1,1,0,1,1,1,0,0},
                                            {0,1,1,1,1,0,1,1,1,0},
                                            {0,0,0,1,1,1,0,1,1,1},
                                            {0,0,0,0,1,1,1,0,1,1},
                                            {0,0,0,0,0,1,1,1,0,1},
                                            {0,0,0,0,0,0,1,1,1,0}};
    int x;
    std::cout << "Choices: " << std::endl;
    std::cout << "1. BFS" << std::endl;
    std::cout << "2. Dijkstra" << std::endl;
    std::cout << "3. Community Detection (Girvan Newman)" << std::endl;
    std::cout << "4. Perform project" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> x;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad entry.  Enter a NUMBER: ";
        std::cin >> x;
    }
    std::cout << "choice = " << x << std::endl;

    if(x==1){
        auto vect = BFS(vect_,0);
        for(unsigned i=0;i<vect.size();i++){
            std::cout<<vect[i]<<" ";
        }
        std::cout<<""<<std::endl;
    } else if(x==2){
        auto vect = dijkstra(vect_,0);
        for(unsigned i=0;i<vect.size();i++){
            std::cout<<vect[i]<<" ";
        }
        std::cout<<""<<std::endl;
    } else if(x==3) {
        auto vect = girvanNewman(vect_);
        for(unsigned i=0;i<vect.size();i++){
            for(unsigned j=0;j<vect[i].size();j++){
                std::cout<<vect[i][j]<< " ";
            }
            std::cout<<""<<std::endl;
        }
    } else if(x==4) {
        auto vect = MakeAdjMatrix("git_data/git_edges.csv", 13000);
        auto communities = girvanNewman(vect);
        auto distances = dijkstra(vect,0); // to change a different starting point replace the 0 with any number
                                            //from  1 to 12999
        
        for(unsigned i = 0; i < communities.size(); i++) {
            auto value = distances[i];

            if (value == 2147483647) {cout << "0 ->" << i <<  " " << "unreachable, separate community"<< endl;}
            else {cout << "0 ->" << i <<  " " << distances[i] << endl;}
        }

        std::cout<<"Complete. Communities detected."<<std::endl;
    } else {
        std::cout<<"Invalid entry"<<std::endl;
    }

    
    return 0;
}

// int main()
// {
//     // Create an adjacency matrix for a graph with 4 nodes
//     vector<vector<int>> adjacencyMatrix = {
//         { 0, 4, 0, 0 },
//         { 4, 0, 8, 0 },
//         { 0, 8, 0, 7 },
//         { 0, 0, 7, 0 }
//     };

//     auto vect = MakeAdjMatrix("/workspaces/CFP/rand.csv", 11);
//     //Get the distances from node 0 to each node in the graph
//     // vector<int> distances = dijkstra(adj, 0);
//     // for (int distance : distances) {
//     //     cout << distance << " ";
//     //     cout << endl;
//     // }

//     for(unsigned i=0;i<vect.size();i++){
//             for(unsigned j=0;j<vect[i].size();j++){
//                 std::cout<<vect[i][j]<< " ";
//             }
//             std::cout<<""<<std::endl;
//     }


// }
