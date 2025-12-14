#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    // Step 1: sort points
    sort(x.begin(), x.end());

    vector<pair<double,double>> intervals;

    int i = 0;
    while (i < n) {
        double start = x[i];
        double end = start + 1.0;

        intervals.push_back({start, end});

        // skip all points covered by this interval
        i++;
        while (i < n && x[i] <= end)
            i++;
    }

    // Output
    cout << "Minimum intervals needed: " << intervals.size() << endl;
    for (auto in : intervals) {
        cout << "[" << in.first << ", " << in.second << "]\n";
    }

    return 0;
}

