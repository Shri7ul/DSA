#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void performDFS(vector<vector<int>>& graph, int startNode) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    s.push(startNode);

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int currentNode = s.top();
        s.pop();

        if (!visited[currentNode]) {
            visited[currentNode] = true;
            cout << currentNode << " ";

            for (int neighbor : graph[currentNode]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph(100);

    addEdge(graph, 10, 30);
    addEdge(graph, 10, 20);
    addEdge(graph, 20, 40);
    addEdge(graph, 20, 50);
    addEdge(graph, 30, 60);

    performDFS(graph, 10);

    return 0;
}

