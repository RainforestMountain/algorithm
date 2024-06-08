#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2, i2 = 1, i3 = 1, i5 = 1; i <= n; i++) {
            int ans = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
            if (ans == dp[i2] * 2) {
                i2++;
            }
            if (ans == dp[i3] * 3) {
                i3++;
            }
            if (ans == dp[i5] * 5) {
                i5++;
            }
            dp[i] = ans;
        }
        for (int i = 1; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << "\n";
        return dp[n];
    }
};

int main() {
    Solution solution;
    cout << solution.nthUglyNumber(10) << "\n";
}
