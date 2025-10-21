#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node *next;
};
Node *graph[100];
int colors[100];

void addEdge(int u,int v){
   Node *newNode=new Node{v,graph[u]};
   graph[u]=newNode;

   newNode=new Node{u,graph[v]};
   graph[v]=newNode;
}

bool isbipartate(int start,int v){
    queue<int>q;

    for(int i=0;i<v;i++) colors[i]=-1;

    colors[start]=0;
    q.push(start);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        Node *temp=graph[u];
        while(temp !=nullptr){
            int v=temp->data;

            if(colors[v]==-1){
                colors[v]=1-colors[u];
                q.push(v);
            }

            else if(colors[v]==colors[u]){
                return false;
            }
            temp=temp->next;
        }

    }
    return true;


}
