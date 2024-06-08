#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        vector<int> dp(n);
        dp[0] = 1;
        int hash[26] = {0};
        for (int i = 1; i < n; i++) {
            if ((s[i - 1] - 'a' + 1) % 26 == (s[i] - 'a')) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += hash[i];
        }

        return ans;
    }
};


int main() {
    Solution solution;
    cout << solution.findSubstringInWraproundString("zaba") << "\n";
}