#include <bits/stdc++.h>
using namespace std;

class Question {
public:
    int id;
    double marks;
    double time;
    double ratio;
};

bool comp(Question a, Question b) {
    return a.ratio > b.ratio;
}

void solve(vector<Question> q, double T, bool printDetail) {
    sort(q.begin(), q.end(), comp);

    double curTime = 0;
    double totalMarks = 0;

    for (int i = 0; i < q.size(); i++) {
        if (curTime >= T) break;

        if (curTime + q[i].time <= T) {
            // full question
            curTime += q[i].time;
            totalMarks += q[i].marks;

            if (printDetail) {
                cout << "ques " << q[i].id
                     << " 100% done -- "
                     << q[i].marks << " marks\n";
            }
        } else {
            // partial question
            double remaining = T - curTime;
            double fraction = remaining / q[i].time;
            double gained = fraction * q[i].marks;

            totalMarks += gained;
            curTime = T;

            if (printDetail) {
                cout << "ques " << q[i].id
                     << " " << fraction * 100
                     << "% done -- "
                     << gained << " marks\n";
            }
        }
    }

    cout << "Maximum " << totalMarks << " marks\n";
}

int main() {
    int M, T, N;
    cin >> M >> T >> N;

    vector<Question> q(N);

    for (int i = 0; i < N; i++) {
        cin >> q[i].marks >> q[i].time;
        q[i].id = i + 1;
        q[i].ratio = q[i].marks / q[i].time;
    }

    cout << "Answering alone:\n";
    solve(q, T, true);

    cout << "\nAnswering with a friend:\n";
    solve(q, 2 * T, false);

    return 0;
}

