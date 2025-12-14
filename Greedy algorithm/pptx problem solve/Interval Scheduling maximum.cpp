#include <bits/stdc++.h>
using namespace std;

class Train {
public:
    int arrival;
    int departure;
};

bool comp(Train a, Train b) {
    return a.departure < b.departure;
}

int main() {
    vector<Train> trains = {
        {1000,1030}, {840,1030}, {850,1040}, {1700,2000},
        {800,835}, {1300,1800}, {1500,1650}, {1200,1380}
    };

    // sort by earliest departure
    sort(trains.begin(), trains.end(), comp);

    int lastDeparture = -100000;
    int count = 0;

    cout << "Selected trains:\n";

    for (int i = 0; i < trains.size(); i++) {
        if (trains[i].arrival >= lastDeparture + 10) {
            cout << "[" << trains[i].arrival << ", "
                 << trains[i].departure << "]\n";
            lastDeparture = trains[i].departure;
            count++;
        }
    }

    cout << "\nMaximum number of trains = " << count << endl;
    return 0;
}

