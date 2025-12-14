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
        {8,12}, {6,9}, {11,14}, {2,7},
        {1,7}, {12,20}, {7,12}, {13,19}
    };

    // Step 1: sort by earliest departure time
    sort(trains.begin(), trains.end(), comp);

    int count = 0;
    int lastDeparture = -1;

    cout << "Selected trains:\n";

    // Step 2: greedy selection
    for (int i = 0; i < trains.size(); i++) {
        if (trains[i].arrival >= lastDeparture + 1) {
            cout << "[" << trains[i].arrival << ", "
                 << trains[i].departure << ")\n";
            count++;
            lastDeparture = trains[i].departure;
        }
    }

    cout << "\nMaximum number of trains = " << count << endl;

    return 0;
}

