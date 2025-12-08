#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

vector<int>coins = {20,4,2};
int target = 125;


sort(coins.begin(),coins.end(),greater<int>());
int total_cnt=0;
for(int coin: coins){


    if(coin<=target){

        int cnt = target/coin;
        target-= cnt*coin;
         total_cnt+=cnt;
         cout<<coin<<" : "<<cnt<<" times"<<endl;
    }

    if(target==0){
        break;
    }



}

if(target>0){
    cout<<"Not possible"<<endl;
}
else{
cout<<" total coins taken: "<<total_cnt<<endl;}

}
