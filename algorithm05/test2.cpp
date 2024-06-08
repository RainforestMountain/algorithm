#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n);
        dp[0] = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                int index = i - dp[i - 1] - 1;
                if (index >= 0 && s[index] == '(') {
                    dp[i] = dp[i - 1] + 2 + (index - 1 >= 0 ? dp[index - 1] : 0);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


int main() {
    string s;
    cin >> s;
    cout << Solution().longestValidParentheses(s) << "\n";
}