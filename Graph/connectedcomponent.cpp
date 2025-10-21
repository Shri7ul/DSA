#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* graph[100]; // adjacency list
bool visited[100]; // visited array

// Add edge (undirected)
void addEdge(int u, int v) {
    Node* newNode = new Node{v, graph[u]};
    graph[u] = newNode;

    newNode = new Node{u, graph[v]};
    graph[v] = newNode;
}

// Print graph (for debug)
void printGraph(int V) {
    cout << "Adjacency List:\n";
    for(int i=0;i<V;i++) {
        if(graph[i] != nullptr){
            cout << i << " -> ";
            Node* temp = graph[i];
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

// DFS function to visit connected nodes
void dfs(int u) {
    visited[u] = true;
    Node* temp = graph[u];
    while(temp != nullptr){
        int v = temp->data;
        if(!visited[v]) dfs(v);
        temp = temp->next;
    }
}

// Function to find connected components
void findConnectedComponents(int V) {
    memset(visited, false, sizeof(visited)); // initialize visited
    cout << "Connected components:\n";
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            // Start DFS for a new component
            dfs(i);
            cout << i << " "; // print one representative node
        }
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

    printGraph(V); // optional

    findConnectedComponents(V);

    return 0;
}

