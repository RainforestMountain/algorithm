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
//�������ҵ�ƫ����
int dx[] = {-1, 1, 0, 0};//��
int dy[] = {0, 0, -1, 1};//��
//�������,ֻ��·��,�������·��
bool dfs(int n, int m, int start_x, int start_y, int end_x, int end_y) {
    //��ջ�ݹ�
    st.push({start_x, start_y});
    visited[start_x][start_y] = true;
    path.push_back({start_x, start_y});
    while (!st.empty()) {
        int x = st.top().x;
        int y = st.top().y;
        int count = 0;//������Ϊ0˵�������û������,Ӧ���˻�,��ջ,·������
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
        if (count == 0) {//��ջ,·������
            path.pop_back();
            st.pop();
        }
    }
    return false;
}

int main() {
    cout << "�����к���";
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
