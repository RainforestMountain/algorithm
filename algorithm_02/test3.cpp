//用优先级队列优化的dijkstra,并且输出路径

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 2;

struct edge {
    int v;
    int w;

    bool operator<(edge e) const {
        return w == e.w ? v < e.v : w > e.w;
    }
};

int path[N];
vector<edge> graph[N];
bitset<N> vis;
int dp[N];

void dijkstra(int v, int n) {
    priority_queue<edge> q;//存放要拓展的顶点
    memset(dp, 0x3f, sizeof(dp[0]) * (n + 1));
    dp[v] = 0;
    q.push({v, dp[v]});
    path[v] = -1;
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (vis[u]) {//避免无效的计算,拓展了就没必要再拓展了
            continue;
        }
        //此时u未向外拓展,并且由于是优先级队列,dp[u]是源点到u的最短路径
        vis[u] = true;//u已经要拓展
        //开始拓展
        for (const auto &ej: graph[u]) {
            int j = ej.v;
            int w = ej.w;
            if (!vis[j] && dp[j] > dp[u] + w) {
                dp[j] = dp[u] + w;
                path[j] = u;//v到j的最短路,j前面的那个点
                q.push({j, dp[j]});//dp[j]未必是最短路径,但是最后dp[j]一定是最短路,因为所有点都拓展了
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int vi, vj, wi;
        cin >> vi >> vj >> wi;
        graph[vi].push_back({vj, wi});
    }
    dijkstra(1, n);
    cout << dp[n] << "\n";
    //输出路径
    int i = n;
    vector<int> res;
    while (i >= 0) {
        res.push_back(i);
        i = path[i];
    }
    reverse(res.begin(), res.end());
    for (auto &val: res) {
        cout << val << " ";
    }
    cout << "\n";
    return 0;
}
