#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int>p,r;

    DSU(int n){
        p.resize(n);
        r.assign(n,0);
        iota(p.begin(),p.end(),0);
    }

    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }

    bool unite(int a,int b){
        a=find(a); b=find(b);

        if(a==b) return false;

        if(r[a]<r[b]) swap(a,b);

        p[b]=a;

        if(r[a]==r[b]) r[a]++;
        return true;
    }

};

struct Edge{
        int u,v;
        int w;
};

int main(){
     int n = 4;

    vector<Edge> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };
   
    sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
        return a.w<b.w;
    });

    DSU dsu(n);
    long long cost =0;
    int taken =0;

    for(auto &e : edges){
        if(dsu.unite(e.u,e.v)){
            cost += e.w;
            taken++;

            if(taken == n-1) break;
        }
    }

    if(taken != n-1) cout<<"Impossible";
    cout<<cost;
}