#include <iostream>
#include <vector>
#include <stack>
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

    void dfs(int start) {
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int current = st.top();
            st.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }
};
