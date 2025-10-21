#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node *graph[100];
bool visited[100];


void addEdge(int u, int v) {
    Node *newNode = new Node{v, graph[u]};
    graph[u] = newNode;

    newNode = new Node{u, graph[v]};
    graph[v] = newNode;
}

void print(int v){
   for(int i=0;i<v;i++){
    if(graph[i] != nullptr){
        cout<<i<<" ";

        Node *temp=graph[i];

        while(temp!=nullptr){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
   }
}

void bfs(int start,int v){
   queue<int>q;

   visited[start]=true;
   q.push(start);


   while(!q.empty()){
    int u=q.front();
    q.pop();

    Node *temp=graph[u];

    while(temp!=nullptr){
        int v=temp->data;

        if(!visited[v]){
            visited[v]=true;
            q.push(v);
        }
        temp=temp->next;
    }
   }
}

bool isconnected(int v){
     int start=0;

     for(int i=0;i<v;i++){
        if(graph[i] !=nullptr){
            start=i;
            break;
        }
     }

     bfs(start,v);

     for(int i=0;i<v;i++){
        if(graph[i] != nullptr && !visited[i]){
            return false;
        }
     }
     return true;

}

int main() {
    int V, edges;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    printGraph(V);

    if (isConnected(V))
        cout << "\n The graph is connected\n";
    else
        cout << "\n The graph is NOT connected\n";

    return 0;
}
