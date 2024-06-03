//prim算法,使用优先级队列,但是这里写的无法获取边,只能知道点

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

struct point {
    int vj;
    int w;

    bool operator<(point e) const {
        if (w != e.w) {
            return w > e.w;
        }
        return vj > e.vj;
    }
};

vector<bool> intree;
vector<point> graph[N];

long long prim(int n) {
    intree = vector(n, false);
    priority_queue<point> q;
    q.push({1, 0});//初始源点最近,为0,最小边为0
    long long ans = 0;
    int cnt = 0;//当点取到n个时有最小生成树
    while (!q.empty()) {
        //选择离生成树最近的点,intree和outtree之间的最小边
        int u = q.top().vj;
        int w = q.top().w;
        q.pop();
        if (intree[u]) {
            continue;
        }
        //u加入生成树集合
        intree[u] = true;
        ans += w;
        cnt++;
        //更新距离,加入候选边,
        for (const auto &val: graph[u]) {
            int vj = val.vj;
            w = val.w;
            if (!intree[vj]) {//不是在intree中
                q.push({vj, w});
            }
        }
    }
    return (cnt == n ? ans : -1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int vi, vj, w;
        cin >> vi >> vj >> w;
        graph[vi].push_back({vj, w});
        graph[vj].push_back({vi, w});
    }
    cout << prim(n) << "\n";
    return 0;
}
