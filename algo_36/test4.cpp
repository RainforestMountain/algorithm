#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mod = 1000000007;
    int waysToStep(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((dp[i - 3] % mod + dp[i - 2] % mod) % mod + dp[i - 1] % mod) % mod;
        }
        return dp[n];
    }
};

int main() {

    Solution solution;
     cout << solution.waysToStep(61) << "\n";
    return 0;
}