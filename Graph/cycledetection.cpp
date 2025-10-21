#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* graph[100]; // adjacency list
bool visited[100];
bool recStack[100]; // recursion stack for cycle detection

// Add edge (directed)
void addEdge(int u, int v) {
    Node* newNode = new Node{v, graph[u]};
    graph[u] = newNode;
}

// DFS to detect cycle
bool dfs(int u) {
    visited[u] = true;
    recStack[u] = true; // mark node in recursion stack

    Node* temp = graph[u];
    while(temp != nullptr) {
        int v = temp->data;
        if(!visited[v]) {
            if(dfs(v)) return true; // cycle found in recursion
        }
        else if(recStack[v]) {
            return true; // back edge found → cycle
        }
        temp = temp->next;
    }

    recStack[u] = false; // remove from recursion stack
    return false;
}

// Check if graph has cycle
bool isCyclic(int V) {
    memset(visited, false, sizeof(visited));
    memset(recStack, false, sizeof(recStack));

    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            if(dfs(i)) return true;
        }
    }
    return false;
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

    if(isCyclic(V))
        cout << "The graph contains a cycle\n";
    else
        cout << "The graph does not contain a cycle\n";

    return 0;
}

