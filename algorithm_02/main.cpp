
//不超时的写法,要写路径压缩
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int pre[N];

int root(int u);

bool isSameSet(int u, int v);

void merge(int u, int v);

int root(int u) {
    if (pre[u] < 0) {
        return u;
    }
    //路径压缩
    pre[u] = root(pre[u]);
    return pre[u];
}

void merge(int u, int v) {
    //相同的集合不需要合并了
    if (isSameSet(u, v)) {
        return;
    }
    int rootu = root(u);
    int rootv = root(v);
    pre[rootv] += pre[rootu];
    pre[rootu] = rootv;
}

bool isSameSet(int u, int v) {
    return root(u) == root(v);
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        pre[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int vi, vj;
        cin >> vi >> vj;
        merge(vi, vj);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (pre[i] < 0) {
            ans.push_back(abs(pre[i]));
        }
    }
    sort(ans.begin(), ans.end());
    for (const auto &item: ans) {
        cout << item << " ";
    }
    cout << "\n";
    return 0;
}
