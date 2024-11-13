#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] <= nums[n - 1]) {
            return nums[0];
        }
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= nums[r]) {
                r = m;
                continue;
            }
            if (nums[m] >= nums[l]) {
                l = m + 1;
                continue;
            }
        }
        return r;

    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,1};
    cout << solution.findMin(nums) << "\n";
    return 0;
}
