#include <bits/stdc++.h>
using namespace std;

class Activity {
public:
    int start;
    int finish;
};

bool comp(Activity a, Activity b) {
    return a.finish < b.finish; // earliest finish first
}

int main() {
    vector<Activity> A = {
        {1,4}, {3,5}, {0,6}, {5,7},
        {3,9}, {5,9}, {6,10}, {8,11},
        {8,12}, {2,14}, {12,16}
    };

    sort(A.begin(), A.end(), comp);

    cout << "Selected activities:\n";

    int lastFinish = A[0].finish;
    cout << "[" << A[0].start << ", " << A[0].finish << ")\n";

    for (int i = 1; i < A.size(); i++) {
        if (A[i].start >= lastFinish) {
            cout << "[" << A[i].start << ", " << A[i].finish << ")\n";
            lastFinish = A[i].finish;
        }
    }

    return 0;
}

