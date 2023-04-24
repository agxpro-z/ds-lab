#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <climits>
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

constexpr int V = 5; // Number of vertices in the graph

class PrimMST {
  public:
    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }

    void printMST(int parent[], int graph[V][V]) {
        std::cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++)
            std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }

    void primMST(int graph[V][V]) {
        int parent[V]; // Array to store constructed MST
        int key[V]; // Key values used to pick minimum weight edge in cut
        bool mstSet[V]; // To represent set of vertices not yet included in MST

        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;

        key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
        parent[0] = -1; // First node is always root of MST

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v];
        }
        printMST(parent, graph);
    }
};

// Dijkstra Algorithm
const int MAX_VERTICES = 100; // Maximum number of vertices

class Dijkstra {
  private:
    int vertices; // Number of vertices in the graph
    int edges[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to represent edges between vertices

  public:
    // Constructor
    Dijkstra(int V) {
        vertices = V;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                edges[i][j] = 0; // Initialize all edges to 0
            }
        }
    }

    // Function to add an edge between two vertices
    void addEdge(int u, int v, int weight) {
        edges[u][v] = weight;
        edges[v][u] = weight; // Since it is an undirected graph
    }

    // Overloaded function to add edges using adjacent matrix
    void addEdge(int** matrix) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                edges[i][j] = matrix[i][j];
            }
        }
    }

    // Function to find the vertex with the minimum distance from the set of vertices not yet processed
    int minDistance(int dist[], bool processed[]) {
        int min = INT_MAX, minIndex;
        for (int v = 0; v < vertices; v++) {
            if (processed[v] == false && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    // Function to print the solution - shortest path from source to all vertices
    void printSolution(int dist[]) {
        std::cout << "Vertex \t Distance from Source\n";
        for (int i = 0; i < vertices; i++) {
            std::cout << i << " \t\t " << dist[i] << "\n";
        }
    }

    // Function to implement Dijkstra's algorithm
    void dijkstra(int src) {
        int dist[MAX_VERTICES]; // Array to store the shortest distance from the source to all vertices
        bool processed[MAX_VERTICES]; // Array to store if a vertex is processed or not

        for (int i = 0; i < vertices; i++) {
            dist[i] = INT_MAX; // Initialize all distances to infinity
            processed[i] = false; // Initialize all vertices as not processed
        }

        dist[src] = 0; // Distance from the source vertex to itself is always 0

        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, processed); // Find the vertex with the minimum distance from the set of vertices not yet processed
            processed[u] = true; // Mark the vertex as processed

            for (int v = 0; v < vertices; v++) {
                if (!processed[v] && edges[u][v] && dist[u] != INT_MAX && dist[u] + edges[u][v] < dist[v]) {
                    // Update dist[v] if there is an edge from u to v and the distance from the source to v
                    // through u is less than the current distance from the source to v
                    dist[v] = dist[u] + edges[u][v];
                }
            }
        }

        printSolution(dist); // Print the solution
    }
};

// #define V 5 // number of vertices // Defined above

class Floyd {
private:
    int graph[V][V];

public:
    Floyd() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = INT_MAX; // initialize all distances to infinity
            }
            graph[i][i] = 0; // initialize distance from a vertex to itself to 0
        }
    }

    void addEdge(int u, int v, int w) {
        graph[u][v] = w; // add edge with weight w
    }

    void floydWarshall() {
        int dist[V][V];

        // initialize dist[][]
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = graph[i][j];
            }
        }

        // compute shortest path for all pairs of vertices
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // print the solution
        std::cout << "\nShorted distances: \n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INT_MAX) {
                    // std::cout << "INF ";
                    printf("%4s", "INF");
                } else {
                    printf("%4d", dist[i][j]);
                    // std::cout << dist[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }
};

} // namespace custom

#endif // GRAPH_HPP
