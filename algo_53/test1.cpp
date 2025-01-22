#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        int max_len = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        vector<int> cnt(n);//以i结尾的最长递增子序列的个数
        cnt[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == dp[i] - 1 && nums[i] > nums[j]) {
                    cnt[i] += cnt[j];//累加上dp[i] - 1, 最长递增子序列长度少1的个数
                }
            }
            cnt[i] = max(1, cnt[i]);
        }
        int res = 0;
        if (max_len == 1) {
            return n;
        } else {
            for (int i = 0; i < n; i++) {
                if (dp[i] == max_len) {
                    res += cnt[i];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {3, 1, 2};
    cout << solution.findNumberOfLIS(nums) << "\n";
    return 0;
}