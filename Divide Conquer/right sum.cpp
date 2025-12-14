#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>>& arr, int low, int mid, int high, vector<int>& count) {
    vector<pair<int,int>> temp;
    int i = low, j = mid + 1;
    int rightSmaller = 0;

    while (i <= mid && j <= high) {
        if (arr[j].first < arr[i].first) {
            // right side smaller element
            rightSmaller++;
            temp.push_back(arr[j]);
            j++;
        } else {
            // left element pushed
            count[arr[i].second] += rightSmaller;
            temp.push_back(arr[i]);
            i++;
        }
    }

    // remaining left elements
    while (i <= mid) {
        count[arr[i].second] += rightSmaller;
        temp.push_back(arr[i]);
        i++;
    }

    // remaining right elements
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    // copy back
    for (int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }
}

void mergeSort(vector<pair<int,int>>& arr, int low, int high, vector<int>& count) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid + 1, high, count);
    merge(arr, low, mid, high, count);
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    int n = nums.size();

    vector<pair<int,int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({nums[i], i}); // value, original index
    }

    vector<int> count(n, 0);
    mergeSort(arr, 0, n - 1, count);

    for (int x : count)
        cout << x << " ";

    return 0;
}

