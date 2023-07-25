#include <iostream>
#include <vector>
#include <queue>
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

    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }
};
