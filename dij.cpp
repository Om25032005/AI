#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices

// Function to find the vertex with the smallest distance that hasn't been visited
int findMinDistance(const vector<int>& dist, const vector<bool>& visited) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's algorithm function
void dijkstra(int graph[V][V], int src) {
    vector<int> dist(V, INT_MAX);     // Stores shortest distances from source to each vertex
    vector<bool> visited(V, false);   // True if vertex is included in shortest path tree

    dist[src] = 0; // Distance from source to itself is always 0

    // Find shortest path to all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(dist, visited); // Get the nearest unvisited vertex
        visited[u] = true;

        // Update distances of adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Check if there's an edge from u to v, and v is unvisited, and the path through u is shorter
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    // Example graph represented using an adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 0},
        {0, 0, 4, 0, 3},
        {5, 2, 0, 3, 0}
    };

    int source = 0; // Starting node
    dijkstra(graph, source);

    return 0;
}
