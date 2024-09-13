#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {

        int n = nums.size();
        vector<int> array(n + 2);
        for (int i = 0; i < n; i++) {
            array[i + 1] = nums[i];
        }
        array[0] = array[n + 1] = 1;

        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = -1;
            }
        }
        slove(array, 1, n, dp);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return dp[1][n];
    }

    int slove(vector<int> array, int left, int right, vector<vector<int>>& dp) {
        if (left > right) {
            return 0;
        }
        if (left == right) {
            dp[left][right] = array[left];
            return array[left];
        }
        if (left == right - 1) {
            dp[left][right] =  array[left] * array[right] + max(array[left], array[right]);
            return dp[left][right];
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        //枚举的k最先打爆
        //边界
//        int ans = max(array[left] * array[left + 1] + slove(array, left + 1, right, dp),
//                      array[right] * array[right - 1] + slove(array, left, right - 1, dp));
//        for (int k = left + 1; k < right; k++) {
//            ans = max(array[k] * array[k - 1] * array[k + 1] + slove(array, left, k - 1, dp) +
//                      slove(array, k + 1, right, dp), ans);
//        }
        int ans = 0;
        for (int k = left; k <= right; k++) {
            int temp = array[k] * array[0] * array[array.size() - 1] + slove(array, left, k - 1, dp) +
            slove(array, k + 1, right, dp);
            ans = max(temp, ans);
        }
        dp[left][right] = ans;
        return ans;

    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums({3, 1, 5, 8});
    cout << solution.maxCoins(nums) << "\n";
    return 0;
}
