#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100000 + 1;

void dfs(int begin, int root, int cur, vector<vector<int>> &graph, vector<int> &kinds, vector<vector<int>> &dp) {
    dp[begin][root] = dp[begin][root] = cur;
    if (graph[root].empty()) {
        return;
    }
    for (const auto &v: graph[root]) {
        dfs(begin, v, cur | (1 << (kinds[root])), graph, kinds, dp);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> kinds(n + 1);
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<int> parent(n + 1);
    unordered_set<int> s;//记录已经出现的节点
    for (int i = 1; i <= n; i++) {
        cin >> kinds[i];
    }
    int root = 0;
    for (int i = 1; i <= n - 1; i++) {
        int ui, vi;
        cin >> ui >> vi;
        if (s.empty()) {
            graph[ui].push_back(vi);
            parent[vi] = ui;
            root = ui;
            s.insert(root);
            continue;
        }
        if (s.find(ui) != s.end()) {
            graph[ui].push_back(vi);
            parent[vi] = ui;
        } else if (s.find(vi) != s.end()) {
            graph[vi].push_back(ui);
            parent[ui] = vi;
        } else {
            graph[ui].push_back(vi);
            parent[vi] = ui;
            s.insert(ui);
        }
    }
    dfs(root, root, 1 << (kinds[root] - 1), graph, kinds, dp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    //从一个节点开始计算

//    for (int i = 1; i <= n; i++) {
//        if (graph[i].empty()) {
//            continue;
//        }
//        cout << i << ": ";
//        for (int j = 0; j < graph[i].size(); j++) {
//            cout << graph[i][j] << " ";
//        }
//        cout << "\n";
//    }

    while (q--) {
        int si, ti;
        cin >> si >> ti;
        if (dp[si][ti] > 0) {
            cout << dp[si][ti];
        } else {
            int sp = parent[si];
            int tp = parent[ti];
            dp[sp][tp] = dp[tp][sp] = 
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

