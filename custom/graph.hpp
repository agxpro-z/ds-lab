#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

#include "queue.hpp"

namespace custom {

// const int MAX_SIZE = 100;

class BFSGraph {
  private:
    int V; // number of vertices
    int** adjMatrix; // adjacency matrix

  public:
    BFSGraph(int vertices) : adjMatrix(nullptr) {
        V = vertices;

        // Create adjacency matrix
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
        }

        // initialize all matrix elements to 0
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // add an edge to the graph
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    // Overloaded addEdge function which takes adjacency matrix
    void addEdge(int** matrix) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = matrix[i][j];
            }
        }
    }

    void bfs(int start) {
        // Create dynamic visited array of defined size.
        bool* visited = new bool[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // create a queue for BFS
        linked_list_queue<int> q;

        // mark the current node as visited and enqueue it
        visited[start] = true;
        q.enqueue(start);
        while(!q.empty()) {
            // dequeue a vertex from queue and print it
            int current = q.front();
            std::cout << current << " ";
            q.dequeue();

            // get all adjacent vertices of the dequeued vertex current
            // if adjacent is not visited, mark it visited and enqueue it
            for(int i = 0; i < V; i++) {
                if(adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.enqueue(i);
                }
            }
        }
    }

    // print adjacency matrix
    void printMatrix() {
        std::cout << "\nAdjacency Matrix:" << std::endl;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

class DFSGraph {
private:
    bool** matrix;
    bool* visited;
    int N;

public:
    DFSGraph(int size) : N(size) {
        // Create adjacency matrix and visited array
        matrix = new bool*[N];
        visited = new bool[N];

        // Initialize adjacency matrix and visited array to false
        for (int i = 0; i < N; i++) {
            matrix[i] = new bool[N];
            for (int j = 0; j < N; j++) {
                matrix[i][j] = false;
            }
            visited[i] = false;
        }
    }

    void addEdge(int u, int v) {
        matrix[u][v] = true;
        matrix[v][u] = true;
    }

    // Overloaded addEdge method which takes data from 2D array
    void addEdge(bool** mat) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = mat[i][j];
            }
        }
    }

    void DFS(int start) {
        visited[start] = true;
        std::cout << start << " ";

        for (int i = 0; i < N; i++) {
            if (matrix[start][i] && !visited[i]) {
                DFS(i);
            }
        }
    }

    void printGraph() {
        for (int i = 0; i < N; i++) {
            std::cout << i << ": ";
            for (int j = 0; j < N; j++) {
                if (matrix[i][j]) {
                    std::cout << j << " ";
                }
            }
            std::cout << std::endl;
        }
        
        std::cout << "\nAdjacency Matrix: \n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j])
                    std::cout << "1 ";
                else
                    std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }
};

} // namespace custom

#endif // GRAPH_HPP
