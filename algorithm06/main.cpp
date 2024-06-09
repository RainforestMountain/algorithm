#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static constexpr int mod = 1000000007;

    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int> last(26, -1);
        vector<int> dp(n, 1);//字符为自身的方案
        for (int i = 0; i < n; i++) {
            //dp[i]是前面的非重复字符和最后一个重复字符的dp[char]的和,非重复字母和重复字母记录最后面出现的位置
            //小写字母只有26个,最多加26次dp[char]
            for (int j = 0; j < 26; j++) {
                if (last[j] != -1) {//在i前面出现过,且是最后面的位置
                    dp[i] = (dp[i] + dp[last[j]]) % mod;
                }
            }
            //更新字符最后面出现的位置
            last[s[i]] = i;
        }
        int ans = 0;//答案是s串各个字母最后一次出现位置作为子串的结尾的总和,只有26个字母,最多出现26次
        for (int i = 0; i < 26; i++) {
            if (last[i] != -1) {
                ans += dp[last[i]];
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
