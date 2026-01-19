#include <bits/stdc++.h>
using namespace std;

class Event {
public:
    char club;
    int start;
    int duration;
    int finish;
};

bool comp(Event a, Event b) {
    return a.finish < b.finish; // earliest finish first
}

int main() {
    int N;
    cin >> N;

    vector<Event> events(N);

    for (int i = 0; i < N; i++) {
        cin >> events[i].club >> events[i].start >> events[i].duration;
        events[i].finish = events[i].start + events[i].duration;
    }

    int X;
    cin >> X;   // cleanup time

    // sort by finish time
    sort(events.begin(), events.end(), comp);

    vector<char> chosen;

    int lastFinish = -100000;

    for (int i = 0; i < N; i++) {
        if (events[i].start >= lastFinish + X) {
            chosen.push_back(events[i].club);
            lastFinish = events[i].finish;
        }
    }

    cout << "Chosen clubs:\n";
    for (char c : chosen) {
        cout << c << " ";
    }

    return 0;
}

