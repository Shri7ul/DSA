#include <bits/stdc++.h>
using namespace std;

int main() {
    int S, N, M;
    cin >> S >> N >> M;

    // Total food required
    int totalFood = S * M;

    // Number of Sundays
    int sundays = S / 7;

    // Days when shop is open
    int openDays = S - sundays;

    // Greedy feasibility check
    if (N < M || openDays * N < totalFood) {
        cout << -1;   // Not possible to survive
        return 0;
    }

    // Greedy minimum buying days
    int minDays = (totalFood + N - 1) / N; // ceil division

    cout << minDays;
    return 0;
}

