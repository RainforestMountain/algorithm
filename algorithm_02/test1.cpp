//朴素的写法 ,O(n ^ 2)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1004;
typedef struct {
    int vertex;
    int weight;
} edge;
vector<edge> graph[N];
int dp[N];
bitset<N> visited;

void dijkstra(int v, int n) {
    memset(dp, 0x3f, sizeof(dp));
    visited[v] = true;
    dp[v] = 0;
    for (int i = 1; i <= n; i++) {
        //找到没有拓展的有最短路径的点
        int minDist = inf;
        int u = 1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dp[j] < minDist) {
                u = j;
                minDist = dp[j];
            }
        }
        visited[u] = true;//已经拓展了
        for (const auto &vj: graph[u]) {
            if (!visited[vj.vertex] && dp[vj.vertex] > dp[u] + vj.weight) {
                dp[vj.vertex] = dp[u] + vj.weight;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int vi, vj, weight;
        cin >> vi >> vj >> weight;
        graph[vi].push_back({vj, weight});
    }
    dijkstra(1, n);
    cout << (dp[n] >= inf ? -1 : dp[n]) << "\n";
    return 0;
}
