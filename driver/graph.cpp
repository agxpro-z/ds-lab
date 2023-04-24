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

void prims_algo_driver() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    cout << "Adjacency Matrix: \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    PrimMST prim;
    prim.primMST(graph);
}

void dijkstra_algo_driver() {
    const int V = 9;
    Dijkstra d(V);

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] < 10)
                cout << "  " << graph[i][j];
            else
                cout << " " << graph[i][j];

            if (graph[i][j] != 0)
                d.addEdge(i, j, graph[i][j]);
        }
        cout << endl;
    }

    int src = 0;
    cout << "Source: " << src << endl;
    d.dijkstra(src);
}

void floyd_algo_driver() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    Floyd f;

    cout << "Adjacency Matrix: \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";

            if (graph[i][j] != 0)
                f.addEdge(i, j, graph[i][j]);
        }
        cout << endl;
    }

    f.floydWarshall(); // find all pair of shortest paths
}
