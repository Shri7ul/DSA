#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* graph[100]; // adjacency list
bool visited[100];
stack<int> topoStack;

// Add edge (directed)
void addEdge(int u, int v) {
    Node* newNode = new Node{v, graph[u]};
    graph[u] = newNode;
}

// DFS for topological sort
void dfs(int u) {
    visited[u] = true;

    Node* temp = graph[u];
    while(temp != nullptr) {
        int v = temp->data;
        if(!visited[v]) {
            dfs(v);
        }
        temp = temp->next;
    }

    topoStack.push(u); // push after visiting all neighbors
}

// Topological sort
void topologicalSort(int V) {
    memset(visited, false, sizeof(visited));

    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    cout << "Topological sort: ";
    while(!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;
}

int main() {
    int V, edges;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> edges;

    for(int i=0;i<edges;i++){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    topologicalSort(V);

    return 0;
}

