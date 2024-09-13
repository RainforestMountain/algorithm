#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = query_row;
        vector<vector<double>> dp(n + 1, vector<double>(n));
        dp[0][0] = poured;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j - 1 >= 0) {
                    dp[i][j] += max((dp[i - 1][j - 1] - 1) / 2, 0.00000);
                }
                if (j <= i - 1) {
                    dp[i][j] += max((dp[i - 1][j] - 1) / 2, 0.00000);;
                }
            }
        }
        return min(dp[n][query_glass - 1], 1.00000);
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.champagneTower(100000009, 33, 17);

}
