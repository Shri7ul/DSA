#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* graph[100];  // adjacency list
bool visited[100];
int parent[100];   // parent array to reconstruct path

void addEdge(int u, int v) {
    Node* newNode = new Node{v, graph[u]};
    graph[u] = newNode;

    newNode = new Node{u, graph[v]};
    graph[v] = newNode;
}

void printGraph(int V) {
    for (int i = 0; i < V; i++) {
        if (graph[i] != nullptr) {
            cout << i << " -> ";
            Node* temp = graph[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

// BFS to find shortest path from start to target
void bfsShortestPath(int start, int target, int V) {
    memset(visited, false, sizeof(visited));
    for(int i=0;i<V;i++) parent[i] = -1;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        Node* temp = graph[u];
        while (temp != nullptr) {
            int v = temp->data;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
            temp = temp->next;
        }
    }

    // Reconstruct path using parent array
    int path[100];
    int count = 0;
    int cur = target;
    while(cur != -1) {
        path[count++] = cur;
        cur = parent[cur];
    }

    cout << "\nShortest path from " << start << " to " << target << ": ";
    for(int i = count-1; i >= 0; i--) cout << path[i] << " ";
    cout << endl;
}

int main() {
    int V = 4;

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);

    printGraph(V);

    int start = 0, target = 3;
    bfsShortestPath(start, target, V);

    return 0;
}

