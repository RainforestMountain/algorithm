#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
        //if (s[i - 1] == s[j - 1] ) dp[i][j] = dp[i + 1][j - 1]
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j) {
                    dp[i][j] = (s[i - 1] == s[j - 1]);
                } else {
                    dp[i][j] = dp[i + 1][j - 1] && s[i - 1] == s[j - 1];
                }
            }
        }
        int l = 0, r = 0, len = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (j - i + 1 > len && dp[i][j]) {
                    l = i - 1;
                    r = j - 1;
                    len = j - i + 1;
                }
            }
        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//
//                cout << dp[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << l << " , " << r << "\n";
        return s.substr(l, r - l + 1);
    }
};

int main() {

    Solution solution;
    string res = solution.longestPalindrome("bababanb");
    cout << res << "\n";
    return 0;
}