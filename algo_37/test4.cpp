#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<string> result;

struct point {
    int x;
    int y;

    point(int x, int y) : x(x), y(y) {}

    bool operator==(const point &o) const {
        return x == o.x && y == o.y;
    }

    // 定义小于比较运算符
    bool operator<(const point &o) const {
        if (x < o.x) return true;
        if (x > o.x) return false;
        return y < o.y;
    }
};

//namespace std {
//    template<>
//    struct hash<point> {
//        size_t operator()(const point &p) const {
//            // 使用 std::hash 为 int 类型提供的标准哈希函数
//            // 并结合 point 的 x 和 y 坐标来计算哈希值
//            return (hash<int>()(p.x) ^ (hash<int>()(p.y) << 1));
//        }
//    };
//}
void dfs(int x, int y, int k, int cur, string &path, vector<vector<int>> &maze, set<point> &vis);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> maze(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maze[i][j];
        }
    }
    set<point> vis;
    vis.insert(point(1, 1));
    string path = "";
    dfs(1, 1, k, maze[1][1], path, maze, vis);
    if (!result.empty()) {
        sort(result.begin(), result.end(), [](auto s1, auto s2) {
            return s1 < s2;
        });
        cout << result[0] << "\n";
    } else {
        cout << -1 << "\n";
    }
}

// cur当前数字序列的值
void dfs(int x, int y, int k, int cur, string &path, vector<vector<int>> &maze, set<point> &vis) {
    int n = maze.size() - 1;
    if (vis.size() >= n * n) {
        if (x == n && y == n) {
            result.push_back(string(path));
        }
    }
    bool ans = false;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && vis.find(point(nx, ny)) == vis.end()
            && (cur + 1) % k == maze[nx][ny]) {
            path.push_back(i + '0');
            vis.insert(point(nx, ny));
            dfs(nx, ny, k, (cur + 1) % k, path, maze, vis);
            path.erase(path.size() - 1, 1);
            vis.erase(vis.find(point{nx, ny}));

        }
    }
}

int main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
//    for (const auto &item: result) {
//        cout << item << "\n";
//    }
//    set<point> s;
//    s.insert(point{4, 5});
//    cout << (s.find(point{4, 5}) != s.end()) << "\n";
//    string s = "hello";
//    s.erase(s.size() - 1, 1);
//    cout << s << "\n";
//    string s1 = "1246";
//    string s2 = "1239";
//    cout << (s1 > s2) << "\n";
    return 0;
}

