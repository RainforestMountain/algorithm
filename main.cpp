#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        prefix[1] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int left = 1;
        int right = 1;
        int len = 0x3f3f3f3f;
        for (; right <= n;) {
            while (left <= right && prefix[right] - prefix[left - 1] >= target) {
                len = min(len, right - left + 1);
                left++;
            }
            right++;
        }
        return len == 0x3f3f3f3f ? 0 : len;
    }
};

int main() {
    vector<int> nums = {1,4,4};
    Solution solution = Solution();
    cout << solution.minSubArrayLen(4, nums) << "\n";
    return 0;
}
