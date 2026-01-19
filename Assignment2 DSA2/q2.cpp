#include<iostream>
#include<algorithm>
using namespace std;

int main(){

int n;
cin>>n;

int g[100][100];

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>g[i][j];
        if(i!=j && g[i][j]==0) g[i][j]=1000000000;
    }
}

int parent[100], key[100], used[100];

for(int i=0;i<n;i++){
    key[i]=1000000000;
    used[i]=0;
    parent[i]=-1;
}

key[0]=0;

for(int cnt=0;cnt<n-1;cnt++){
    int u=-1, mn=1000000000;
    for(int v=0;v<n;v++){
        if(!used[v] && key[v]<mn){
            mn=key[v];
            u=v;
        }
    }

    used[u]=1;

    for(int v=0;v<n;v++){
        if(!used[v] && g[u][v]<key[v]){
            key[v]=g[u][v];
            parent[v]=u;
        }
    }
}

int total=0;
for(int i=1;i<n;i++){
    cout<<parent[i]<<" "<<i<<" "<<g[parent[i]][i]<<endl;
    total+=g[parent[i]][i];
}
cout<<total<<endl;

}
