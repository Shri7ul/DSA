//Given an array of size n, return the majority element.The majority element is the element that appears more than ⌊n/2⌋ times. You may assume that the majority element always exists in the array


#include <bits/stdc++.h>
using namespace std;

int countInRange(vector<int>& nums, int num, int low, int high) {
    int cnt = 0;
    for (int i = low; i <= high; i++) {
        if (nums[i] == num)
            cnt++;
    }
    return cnt;
}

int majorityDC(vector<int>& nums, int low, int high) {
    // base case: one element
    if (low == high)
        return nums[low];

    int mid = (low + high) / 2;

    int leftMajor  = majorityDC(nums, low, mid);
    int rightMajor = majorityDC(nums, mid + 1, high);

    // if both halves agree
    if (leftMajor == rightMajor)
        return leftMajor;

    // otherwise, count both in current range
    int leftCount  = countInRange(nums, leftMajor, low, high);
    int rightCount = countInRange(nums, rightMajor, low, high);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};

    cout << majorityDC(nums, 0, nums.size() - 1);
    return 0;
}
