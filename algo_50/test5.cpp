#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, int status, set<pair<int, int>> &vis, vector<vector<int>> &maze) {
    int n = maze.size();
    int m = maze[0].size();
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis.find({nx, ny}) == vis.end()) {
            if (status == 1 && maze[x][y] < maze[nx][ny]) {//应该上坡了
                vis.insert({nx, ny});
                ans = max(ans, 1 + dfs(nx, ny, 0, vis, maze));
                vis.erase({nx, ny});
            }
            if (status == 0 && maze[x][y] > maze[nx][ny]) {//应该下坡了
                vis.insert({nx, ny});
                ans = max(ans, 1 + dfs(nx, ny, 1, vis, maze));
                vis.erase({nx, ny});
            }
        }
    }
    return ans;
}

int solution(int m, int n, vector<vector<int>> &a) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here

    int ans = 0;
    set<pair<int, int>> vis;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            ans = max(ans, dfs(i, j, 0, vis, a));
            vis.clear();
            ans = max(ans, dfs(i, j, 1, vis, a));
            vis.clear();
        }
    }
    //cout << ans - 1 << "\n";
    return ans - 1;
}

int main() {
//    vector<vector<int>> a1 = {{1, 2},
//                              {4, 3}};
//    cout << (solution(2, 2, a1) == 3) << endl;
//
//    vector<vector<int>> a2 = {{10, 1, 6},
//                              {5,  9, 3},
//                              {7,  2, 4}};
//    cout << (solution(3, 3, a2) == 8) << endl;

//    vector<vector<int>> a3 = {{8,  3,  2,  1},
//                              {4,  7,  6,  5},
//                              {12, 11, 10, 9},
//                              {16, 15, 14, 13}};
//    cout << (solution(4, 4, a3) == 11) << endl;
    vector<vector<int>> a4 = {{2,  14},
                              {10, 11},
                              {3,  15}};
    cout << (solution(3, 2, a4) == 5) << endl;
}