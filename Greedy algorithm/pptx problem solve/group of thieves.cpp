#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    string name;
    double weight;
    double value;
};

bool comp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

int main() {
    vector<Item> items;

    Item i1;
    i1.name = "Rice";
    i1.weight = 12;
    i1.value = 840;
    items.push_back(i1);

    Item i2;
    i2.name = "Salt";
    i2.weight = 10;
    i2.value = 870;
    items.push_back(i2);

    Item i3;
    i3.name = "Saffron";
    i3.weight = 8;
    i3.value = 2000;
    items.push_back(i3);

    Item i4;
    i4.name = "Sugar";
    i4.weight = 5;
    i4.value = 500;
    items.push_back(i4);

    // sort by value per kg (greedy)
    sort(items.begin(), items.end(), comp);

    int thief = 1;
    double CAP = 9;

    while (true) {
        double capacity = CAP;
        double profit = 0;
        bool tookSomething = false;

        cout << "\nThief " << thief << " takes:\n";

        for (int i = 0; i < items.size(); i++) {
            if (items[i].weight == 0 || capacity == 0)
                continue;

            double take = min(capacity, items[i].weight);
            double unitValue = items[i].value / items[i].weight;

            profit += take * unitValue;
            items[i].weight -= take;
            capacity -= take;

            if (take > 0) {
                cout << "- " << take << " kg " << items[i].name << endl;
                tookSomething = true;
            }
        }

        if (!tookSomething)
            break;

        cout << "Profit: " << profit << " taka\n";
        thief++;
    }

    cout << "\nTotal thieves needed: " << thief - 1 << endl;
    return 0;
}
