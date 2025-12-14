#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {1, 3, 5, 9};
    sort(A.begin(), A.end());

    int moves = 0;

    for (int i = 0; i < A.size(); ) {
        if (i + 1 < A.size() && A[i+1] - A[i] <= 2) {
            // remove two elements
            moves++;
            i += 2;
        } else {
            // remove one element
            moves++;
            i += 1;
        }
    }

    cout << moves;
    return 0;
}

