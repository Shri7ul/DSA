//Count total vowels in a string using divide and conquer technique.

#include <bits/stdc++.h>
using namespace std;

int CountVowel(string &s, int low, int high) {
    if (low == high) {
        char c = s[low];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return 1;
        else
            return 0;
    }

    int mid = (low + high) / 2;

    int left  = CountVowel(s, low, mid);
    int right = CountVowel(s, mid + 1, high);

    return left + right;
}

int main() {
    string s = "Sakib";

    int n = s.length();
    cout << CountVowel(s, 0, n - 1);

    return 0;
}
