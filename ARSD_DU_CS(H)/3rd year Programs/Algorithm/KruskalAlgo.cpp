#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;

    // Comparator function for sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Function to find the parent of a node in the disjoint-set
int findParent(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent); // Path compression
    }
    return parent[node];
}

// Function to perform union of two subsets
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Function to find the MST using Kruskal's Algorithm
void kruskalMST(int vertices, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // Sort edges by weight

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    // Initialize disjoint-set
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    vector<Edge> mst; // Store the MST edges
    int mstWeight = 0;

    // Process edges
    for (const Edge& edge : edges) {
        int uParent = findParent(edge.src, parent);
        int vParent = findParent(edge.dest, parent);

        // If adding this edge does not form a cycle
        if (uParent != vParent) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            unionSets(uParent, vParent, parent, rank);
        }
    }

    // Print the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int vertices, edgesCount;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(vertices, edges);

    return 0;
}
