#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    s.insert(s.begin(), '0');
    t.insert(t.begin(), '0');
    int n = s.size() - 1;
    int m = t.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    //dp[i][j] 以i结尾的s的子序列等于以j结尾的t 的最小操作次数
    //子序列, 不一定是dp[i - 1][j - 1]

    for (int j = 1; j <= m; j++) {
        int mi = 0x3f3f3f3f;
        for (int i = j; i <= n; i++) {
            mi = min(mi, dp[i - 1][j - 1]);//实时更新
            if (s[i] == t[j]) {
                dp[i][j] = mi;
            } else {
                dp[i][j] = mi + 1;
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    int res = 0x3f3f3f3f;
    for (int i = m; i <= n; i++) {
        res = min(res, dp[i][m]);
    }
    cout << res << "\n";
//    cout << dp[n][m] << "\n";
}

int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
