#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//多叉树

vector<vector<int>> t1;//树中边的情况, t[i] = {...}, 里面是子结点
vector<vector<int>> t2;
vector<int> w1;
vector<int> w2;

/**
 * //找到没有办法相等的时候
 * @param cur1 此时走到的节点下标
 * @param cur2 此时走到的节点下标
 * @return
 */
int dfs(int cur1, int cur2) {
    if (t1[cur1].empty() || t2[cur2].empty()) {
        return 0;
    }
    int ans = -1;
    for (int i = 0; i < t1[cur1].size(); i++) {
        int val1 = w1[t1[cur1][i]];
        for (int j = 0; j < t2[cur2].size(); j++) {
            int va12 = w2[t2[cur2][j]];
            if (val1 != va12) {
                continue;
            }
            ans = max(ans, dfs(t1[cur1][i], t2[cur2][j]));
        }
    }
    return ans + 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    w1 = vector<int>(n + 1);
    w2 = vector<int>(m + 1);
    t1 = vector<vector<int>>(n + 1, vector<int>());
    t2 = vector<vector<int>>(m + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> w1[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> w2[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int ui, vi;
        cin >> ui >> vi;
        t1[min(ui, vi)].push_back(max(ui, vi));
    }
    t1[0].push_back(1);
    for (int i = 1; i <= m - 1; i++) {
        int pi, qi;
        cin >> pi >> qi;
        t2[min(pi, qi)].push_back(max(pi, qi));
    }
    t2[0].push_back(1);
    int res = dfs(0, 0);//为了遍历到根
    cout << res << "\n";
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve();

    return 0;
}
