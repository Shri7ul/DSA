#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, m, n;
    cin >> D;
    cin >> m;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    int current = 0;   // current position
    int i = 0;
    vector<int> stops;

    while (current + m < D) {
        int last = current;

        // move to the farthest reachable gas station
        while (i < n && d[i] <= current + m) {
            last = d[i];
            i++;
        }

        // no station found within reach
        if (last == current) {
            cout << "Can't reach destination";
            return 0;
        }

        stops.push_back(last);
        current = last;
    }

    // print result
    for (int j = 0; j < stops.size(); j++) {
        cout << "stop at gas station " << j + 1
             << " (" << stops[j] << " miles)\n";
    }

    return 0;
}

