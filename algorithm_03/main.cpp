//dfs暴搜求最短路径,用栈实现递归
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
vector<point> path;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(point &v, int n, int m) {
    stack<point> st;
    st.push(v);
    vis[v.x][v.y] = true;
    path.push_back(v);
    point cur = v;
    int step = 0;
    int minstep = n * n;
    while (!st.empty()) {
        cur = st.top();
        if (step > minstep) {
            st.pop();
            vis[cur.x][cur.y] = false;//无法保证第一次走的点是最短路径的点
            path.pop_back();
            step--;
            continue;
        }
        if (cur.x == n && cur.y == m) {
            if (step < minstep) {
                minstep = step;
                path.push_back(cur);
            }
        }

        //四个方向
        bool flag = false;//如果四个方向都走不通,还是为false
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && maze[nx][ny] == 0) {
                flag = true;
                path.push_back({nx, ny});
                st.push({nx, ny});
                vis[nx][ny] = true;
                step++;
                break;
            }
        }
        //走不通,要回溯
        if (!flag) {
            st.pop();
            vis[cur.x][cur.y] = false;//无法保证第一次走的点是最短路径的点
            path.pop_back();
            step--;
        }
    }
    return false;
}


int main() {
    cout << "输入迷宫" << "\n";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maze[i][j];
        }
    }
    point v = {1, 1};
    cout << dfs(v, n, n) << "\n";
    for (const auto &item: path) {
        cout << "(" << item.x << "," << item.y << ")";
    }
    cout << "\n";
    return 0;
}
