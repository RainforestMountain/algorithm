#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 500;
int maze[N][N];
struct point {
    int x;
    int y;
};
vector<point> path;
bitset<N> visited[N];
stack<point> st;
//上下左右的偏移量
int dx[] = {-1, 1, 0, 0};//行
int dy[] = {0, 0, -1, 1};//列
//深度优先,只求路径,不求最短路径
bool dfs(int n, int m, int start_x, int start_y, int end_x, int end_y) {
    //用栈递归
    st.push({start_x, start_y});
    visited[start_x][start_y] = true;
    path.push_back({start_x, start_y});
    while (!st.empty()) {
        int x = st.top().x;
        int y = st.top().y;
        int count = 0;//如果这个为0说明这个点没法走了,应该退回,退栈,路径回溯
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n - 2 && ny >= 1 && ny <= n - 2 && !visited[nx][ny] && maze[nx][ny] == 0) {
                path.push_back({nx, ny});
                st.push({nx, ny});
                visited[nx][ny] = true;
                if (nx == end_x && ny == end_y) {
                    return true;
                }
                count++;
                break;
            }

        }
        if (count == 0) {//退栈,路径回溯
            path.pop_back();
            st.pop();
        }
    }
    return false;
}

int main() {
    cout << "输入行和列";
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    dfs(n, m, 1, 1, n - 2, m - 2);
    for (const auto &item: path) {
        cout << "(" << item.x << "," << item.y << ") ";
    }
    cout << "\n";
    while (!st.empty()) {
        cout << "(" << st.top().x << "," << st.top().y << ") ";
        st.pop();
    }
    cout << "\n";
    return 0;
}
