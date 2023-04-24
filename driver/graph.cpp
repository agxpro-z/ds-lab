#include <iostream>

#include "../custom/graph.hpp"
#include "graph.hpp"

using namespace custom;
using namespace std;

void bfs_driver() {
    BFSGraph g(5);
    // g.addEdge(0, 1);
    // g.addEdge(0, 4);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);

    const int size = 5;
    int matrix[size][size] = {
        {0,1,0,0,1},
        {1,0,1,1,1},
        {0,1,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}
    };

    int** adjMatrix = new int*[size];
    for (int i = 0; i < size; i++) {
        adjMatrix[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adjMatrix[i][j] = matrix[i][j];
        }
    }

    g.addEdge(adjMatrix);
    g.printMatrix();
    cout << "Breadth-first search starting from vertex 0:" << endl;
    g.bfs(0);
    cout << endl;
}

void dfs_driver() {
    DFSGraph g(5);
    // g.addEdge(0, 1);
    // g.addEdge(0, 4);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);

    const int size = 5;
    bool matrix[size][size] = {
        {0,1,0,0,1},
        {1,0,1,1,1},
        {0,1,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}
    };

    bool** adjMatrix = new bool*[size];
    for (int i = 0; i < size; i++) {
        adjMatrix[i] = new bool[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adjMatrix[i][j] = matrix[i][j];
        }
    }

    g.addEdge(adjMatrix);
    std::cout << "Graph: " << std::endl;
    g.printGraph();
    cout << "Depth-first search starting from vertex 1:" << endl;
    g.DFS(1);
    cout << endl;
}
