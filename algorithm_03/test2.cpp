
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 100005;

struct edge {
    int vi;
    int vj;
    int w;

    bool operator<(edge e) const {
        if (w != e.w) {
            return w > e.w;
        }
        return vj > e.vj;
    }
};

//并查集
int pre[N];

int root(int v) {
    if (pre[v] == v) {
        return v;
    }
    pre[v] = root(pre[v]);
    return pre[v];
}

void merge(int v, int u) {
    pre[root(v)] = root(u);
}

bool isSameSet(int v, int u) {
    return root(v) == root(u);
}

priority_queue<edge> q;
vector<edge> result;

ll kruskal(int n) {
    ll ans = 0;
    int cnt = 0;//记录选的边数
    while (!q.empty()) {
        int vi = q.top().vi;
        int vj = q.top().vj;
        int w = q.top().w;
        q.pop();
        if (isSameSet(vi, vj)) {
            continue;
        }
        result.push_back({vi, vj, w});
        ans += w;
        cnt++;
        //加入并查集
        merge(vi, vj);
        if (cnt == n - 1) {
            return ans;
        }
    }
    return (cnt == n - 1 ? ans : -1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int vi, vj, w;
        cin >> vi >> vj >> w;
        q.push({vi, vj, w});
    }
    cout << kruskal(n) << "\n";
    //输出选的边
    for_each(result.begin(), result.end(),
                  [](edge val) { cout << val.vi << "->" << val.vj << ": " << val.w << "\n"; });
    return 0;
}