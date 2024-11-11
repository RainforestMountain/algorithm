#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200000 + 4;

int dp[3001];
bitset<3002> vis;

struct power {
public:
    int pi;
    vector<int> val;

    power() {
    }

    power(int pi) {
        this->pi = pi;
        val = vector<int>(pi + 1);
    }
};

void dfs(int index, int maxS, vector<vector<int>> &p) {
    if (index < 1) {
        return;
    }
    //这个点到底选没有选
    //选了
    if (dp[maxS - p[index - 1][0]] + p[index - 1][p[index - 1][0]] == dp[maxS]) {
        vis[index] = true;
        dfs(index - 1, maxS - p[index - 1][0], p);
    } else {//没选
        dfs(index - 1, maxS, p);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> p(n + 1, vector<int>(11));
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int pi;
        cin >> pi;
        p[i][0] = pi;
        sum += pi;
        for (int j = 1; j <= p[i][0]; j++) {
            cin >> p[i][j];
        }
    }
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + p[i][0];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = prefix[i - 1]; j >= 0; j--) {
            dp[j] = dp[j];
            if (i > 0 && j - p[i][0] >= 0 && j <= k) {
                dp[j] = max(dp[j], dp[j - p[i][0]] + p[i][p[i][0]]);
            }
        }
    }
//    for (int i = 1; i <= n + 1; i++) {
//        for (int j = 0; j <= sum; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    int ans = 0;
    int maxS = 0;
    for (int j = 0; j <= sum; j++) {
        if (dp[j] > ans) {
            maxS = j;
            ans = dp[j];
        }
    }
    //在找部分升级的
    //确定路径
    int index = n + 1;
    dfs(index, maxS, p);
//    for (const auto &item: path) {
//        cout << item << " ";
//    }
//    cout << "\n";
    //部分
    for (int i = 1; i <= n + 1; i ++ ) {
        if (vis[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    int val = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && k - maxS > 0 && maxS + p[i][0] > k) {
            val = max(val, p[i][k - maxS]);
        }
    }
    cout << val + ans << "\n";
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

