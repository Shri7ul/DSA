//You are given a list of students who have name, id and cgpa. Your task is to find the student with highest cgpa. [ you can’t sort the list]
#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int id;
    float cgpa;
};

Student highestCGPA(vector<Student>& s, int low, int high) {
    // base case: one student
    if (low == high) {
        return s[low];
    }

    int mid = (low + high) / 2;

    Student leftBest  = highestCGPA(s, low, mid);
    Student rightBest = highestCGPA(s, mid + 1, high);

    // combine
    if (leftBest.cgpa > rightBest.cgpa)
        return leftBest;
    else
        return rightBest;
}

int main() {
    vector<Student> students = {
        {"Sakib", 101, 3.75},
        {"Tamim", 102, 3.90},
        {"Rakib", 103, 3.60},
        {"Nafisa", 104, 3.95},
        {"Arafat", 105, 3.80}
    };

    Student ans = highestCGPA(students, 0, students.size() - 1);

    cout << "Top Student:\n";
    cout << "Name: " << ans.name << endl;
    cout << "ID: " << ans.id << endl;
    cout << "CGPA: " << ans.cgpa << endl;

    return 0;
}

