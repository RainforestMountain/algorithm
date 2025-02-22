#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(int rt, vector<vector<int>> &graph, vector<int> &f, set<int> &vis) {
    int n = graph.size() - 1;
    vis.insert(rt);
    for (int child: graph[rt]) {
        if (vis.find(child) == vis.end()) {
            dfs(child, graph, f, vis);
        }
    }
    for (int t = rt; t <= n; t += rt) {
        //如果t是rt的上面的节点, t的子树有rt
        if (vis.find(t) != vis.end()) {
            f[t]++;
        }
    }
    vis.erase(rt);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, rt;
    cin >> n >> rt;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> f(n + 1);
    set<int> vis;
//    vector<bool> isPrime(n + 1, true);
//    for (int i = 2; i <= n; i++) {
//        if (isPrime[i]) {
//            for (int t = 2 * i; t <= n; t += i) {
//                isPrime[t] = false;
//            }
//        }
//    }
    dfs(rt, graph, f, vis);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += f[i];
    }
    cout << res << "\n";
    return 0;
}
