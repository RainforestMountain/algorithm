//dfs暴搜求最短路径,注意回溯vis
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 305;
int maze[N][N];
bitset<N> vis[N];
struct point {
    int x;
    int y;
};
vector<vector<point>> paths;
vector<point> path;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int res = 0x3f3f3f3f;

void dfs(int x, int y, int n, int m, int step) {
    if (step >= res) {
        return;
    }
    if (x == n && y == m) {
        res = min(res, step);
        paths.push_back(path);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && maze[nx][ny] == 0 && !vis[nx][ny]) {
            vis[nx][ny] = true;
            path.push_back({nx, ny});
            dfs(nx, ny, n, m, step + 1);
            vis[nx][ny] = false;
            path.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }
    vis[1][1] = true;
    dfs(1, 1, n, m, 0);
    cout << res << "\n";
//    //输出所有路径
//    for (const auto &val: paths) {
//        for (const auto &item: val) {
//            cout << "(" << item.x << "," << item.y << ")";
//        }
//        cout << "\n";
//    }
    return 0;
}
