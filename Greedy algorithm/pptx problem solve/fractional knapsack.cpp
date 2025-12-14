#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
   double weight;
   double profit;
};

bool comp (Item i1,Item i2){
  double u1 = i1.profit/i1.weight;
  double u2 = i2.profit/i2.weight;

  return u1>u2;
}

int main(){
   vector<double> weights = {10,30,20};
   vector<double> profits = {60,120,100};
    double max_cap = 50;

    vector<Item> item;

    for(int i=0;i<weights.size();i++){
        Item items;
        items.weight=weights[i];
        items.profit=profits[i];
        item.push_back(items);
    }
    cout<<item[2].weight<<endl;
    sort(item.begin(),item.end(),comp);
    cout<<item[2].weight<<endl;
    double profit = 0;

    for(Item items : item){
        if(items.weight<=max_cap){
            max_cap -= items.weight;
            profit += items.profit;
        }
        else {
            profit += max_cap * (items.profit / items.weight);
            max_cap=0;

        }
        if(max_cap == 0) break;
    }
    cout<<profit;

}
