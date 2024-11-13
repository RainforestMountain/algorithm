#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                }
                dp[i][j] += min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << ' ';
                res = max(res, dp[i][j]);
            }
            cout << '\n';
        }
        return res * res;
    }
};

int main() {

    Solution solution;
    vector<vector<char>> matrix = {{'1', '1', '1', '1', '0'},
                                   {'1', '1', '1', '1', '0'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'0', '0', '1', '1', '1'}};
    cout << solution.maximalSquare(matrix) << '\n';
    return 0;
}