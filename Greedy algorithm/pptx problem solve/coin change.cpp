#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>coins = {8,4,2};
    int target = 124;

    sort(coins.begin(),coins.end(),greater<int>());
    int total_coin = 0;

    for(int coin : coins){
        if(coin<=target){
            int cnt = target/coin;
            target -= cnt*coin;
            total_coin += cnt;
            cout<<coin<<" : "<<cnt<<" times"<<endl;
        }
        if(target == 0)
            break;

    }
    if(target>0) cout<<"Impossible"<<endl;
    else cout<<total_coin;
}
