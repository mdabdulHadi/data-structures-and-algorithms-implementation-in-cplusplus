#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    Graph(int numVertices) : V(numVertices), adjList(numVertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For an undirected graph
    }

    void display() {
        for (int v = 0; v < V; ++v) {
            cout << "Adjacency list of vertex " << v << ": ";
            for (int neighbor : adjList[v]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};
