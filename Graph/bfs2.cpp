#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node *next;
};

Node *graph[100];

void addEdge(int u,int v){
    Node *newNode=new Node{v,graph[u]};
    graph[u]=newNode;

    newNode=new Node{u,graph[v]};
    graph[v]=newNode;
}

void print(){
     for(int i=0;i<100;i++){
        if(graph[i]!=nullptr){
            cout<<i<<"->";
            Node *temp=graph[i];
            while(temp != nullptr){
               cout<<temp->data<<" ";
               temp=temp->next;
            }
            cout<<endl;
        }
     }
}
void dfs(int start){
   stack<int>st;
   bool visited[100]={false};

   visited[start]=true;
   st.push(start);

   while (!st.empty()){
    int curr=st.top();
    st.pop();
    cout<<curr<<" ";
    int neighbors[100];
    int Count=0;

    Node *temp=graph[curr];
    while(temp !=nullptr){
        neighbors[Count++]=temp->data;
        temp=temp->next;
    }


   for(int i=0;i<Count;i++){
        int neighbor=neighbors[i];

        if(!visited[neighbor]){
            visited[neighbor]=true;
            st.push(neighbor);
        }

    }

   }
   cout<<" ";
}

int main(){
    int edge;
    cout<<"Enter Edge size";
    cin>>edge;

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;

        addEdge(u,v);
    }
    print();

    int start;
    cout << "\nEnter starting node for BFS: ";
    cin >> start;

    dfs(start);

    return 0;
}
