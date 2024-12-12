#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int one = 0;
        int zero = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') one++;
            if (s[i] == '0') zero++;
        }
        int left = 0;
        int right = one;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                left++;
                ans = max(ans, left + right);
            } else {
                right--;
                ans = max(ans, left + right);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.maxScore("00111") << "\n";
    return 0;
}
