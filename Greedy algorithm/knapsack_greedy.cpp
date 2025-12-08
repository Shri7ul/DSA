#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{

public:

  double weight,profit;



};
//custom sort by unit proft in descending order
bool comp(Item i1 , Item i2){
double unit_prof_i1 = i1.profit/i1.weight;
double unit_prof_i2 = i2.profit/i2.weight;
return unit_prof_i1>unit_prof_i2;
}



int main(){

vector<double> weights = {10,30,20};
vector<double> profits = {60,120,100};
double max_cap = 50;

vector<Item> items;

for(int i=0;i<weights.size();i++){

    Item item;
    item.weight=weights[i];
    item.profit=profits[i];
    items.push_back(item);
}
cout<<items[2].weight<<endl;
sort(items.begin(),items.end(),comp);

cout<<items[2].weight<<endl;
double max_profit=0;
for(Item item:items){
    if(item.weight<=max_cap){
       //we can take the whole item
       max_cap-=item.weight;
       max_profit+=item.profit;

    }
    else{
        //we have to take it fractionally
        max_profit+= max_cap*(item.profit/item.weight);
        max_cap=0;
    }

    if(max_cap==0){
        break;
    }
}

cout<<max_profit<<endl;

}
