#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
    int v = 1;
    int j = 1;//v -> j
    ll weight;

    edge(int v, int j, ll weight) : v(v), j(j), weight(weight) {}

    edge() {}

    bool operator<(const edge &o) const {
        return weight > o.weight;
    }
};


//跳跃问题转换为找到惩罚的最短路径问题
void solve() {
    int n;
    cin >> n;
    vector<vector<edge>> graph(n + 1);
    priority_queue<edge> q;
    vector<ll> dp(n + 1, LONG_LONG_MAX / 2);
    vector<bool> vis(n + 1);
    vector<ll> prefix(n + 1);
    vector<ll> a(n + 1);
    vector<int> b(n + 1);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            graph[i].push_back({i, i - 1, 0});
        } else {
            if (b[i] != i) {
                dp[b[i]] = a[i];
            }
        }
        prefix[i] = prefix[i - 1] + a[i];
        if (i != b[i] && i - b[i] != 1) {
            graph[i].push_back({i, b[i], a[i]});
        }
    }
    //1为起始点
    for (int i = 2; i <= n; i++) {
        q.push({1, i, dp[i]});
    }
    vis[1] = true;
    for (int i = 2; i <= n; i++) {//要拓展n - 1次
        //找到没有拓展点里面离源点最近的点m
        while (!q.empty() && vis[q.top().j]) {
            q.pop();
        }
        edge minE;
        if (!q.empty()) {//找到了
            minE = q.top();
            q.pop();
        }
        vis[minE.j] = true;//已经拓展了
        //更新其他没有拓展点与源点的距离
        //只需要更新与m相连的即可
        for (const auto &edge: graph[minE.j]) {
            if (!vis[edge.j]) {
                dp[edge.j] = min(dp[edge.j], dp[edge.v] + edge.weight);
                q.push({1, edge.j, dp[edge.j]});
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(prefix[i] - dp[i], ans);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}
