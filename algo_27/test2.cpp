
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        //前i个字符,前j个字符, 能否匹配
        if (s == "") {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (p == "") {
            return false;
        }
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*' && dp[0][j - 1]) {
                dp[0][j] = dp[0][j - 1];
            } else {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (p[0] == '*') {
                dp[i][1] = true;
            } else if (p[0] == '?') {
                dp[1][1] = true;
            } else {
                if (s[0] == p[0]) {
                    dp[1][1] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                if (p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
//                    if (dp[i - 1][j - 1]) {
//                        dp[i][j] = dp[i - 1][j - 1];
//                    } else {
//                        for (int k = i; k >= 1; k--) {
//                            if (dp[k][j - 1]) {
//                                dp[i][j] = dp[k][j - 1];
//                                break;
//                            }
//                        }
//                    }
                    dp[i][j] = dp[i][j - 1] || dp[i][j - 1];
                } else {
                    if (p[j - 1] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return dp[n][m];

    }
};

int main() {

    Solution solution;
    cout << solution.isMatch("ho", "***ho") << "\n";
    return 0;
}
