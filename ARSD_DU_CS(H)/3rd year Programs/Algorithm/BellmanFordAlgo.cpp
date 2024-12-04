#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(int vertices, int edgesCount, vector<Edge>& edges, int source) {
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    // Relax all edges (vertices - 1) times
    for (int i = 1; i <= vertices - 1; i++) {
        for (const Edge& edge : edges) {
            if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
                distance[edge.dest] = distance[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
            cout << "Graph contains a negative-weight cycle!" << endl;
            return;
        }
    }

    // Print the distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << endl;
    }
}

int main() {
    int vertices, edgesCount;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(vertices, edgesCount, edges, source);

    return 0;
}
