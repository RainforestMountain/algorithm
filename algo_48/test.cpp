#include <bits/stdc++.h>

using namespace std;


// 如果跳到的位置超过范围就是不可以了
int sx, sy, ex, ey;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int da[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int db[] = {-2, 2, -1, 1, -2, 2, -1, 1};
int mi = 20;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void init() {
    if (sx <= ex && sy <= ey) {
    } else if (sx <= ex && sy >= ey) {
        swap(sy, ey);
    } else if (sx >= ex && sy <= ey) {
        swap(sx, ex);
    } else {
        swap(sx, ex);
        swap(sy, ey);
    }
}

//bool isRange(int x, int y) {
//    if (x < sx - 2 || y < sy - 2 || x > ex + 2 || y > ey + 2) {
//        return false;
//    }
//    return true;
//}

int dynamical(int x, int y, int cur, set<pair<int, int>> &vis, map<pair<int, int>, int> &dp) {
    if (cur > mi) {
        return mi;
    }
    if (x == ex && y == ey) {
        mi = min(mi, cur);
        return 0;
    }

    if (dp.find({x, y}) != dp.end()) {
        mi = min(mi, cur + dp[{x, y}]);
        return dp[{x, y}];
    }
    int ans = INT_MAX / 2;
    //象
    for (int i = 0; i < 4; i++) {
        for (int k = 1; k <= ex - sx; k++) {
            int nx = x + dx[i] * k;
            int ny = y + dy[i] * k;
            if (vis.find({nx, ny}) == vis.end()) {
                //可以过去
                vis.insert({nx, ny});
                int tmp = dynamical(nx, ny, cur + 1, vis, dp);
                ans = min(ans, tmp + 1);
                vis.erase({nx, ny});
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + da[i];
        int ny = y + db[i];
        if (vis.find({nx, ny}) == vis.end()) {
            vis.insert({nx, ny});
            ans = min(ans, dynamical(nx, ny, cur + 1, vis, dp) + 1);
            vis.erase({nx, ny});
        }
    }
    dp[{x, y}] = ans;
    return ans;
}

int solution(int x1, int y1, int x2, int y2) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    //预处理
    map<pair<int, int>, int> dp;
    set<pair<int, int>> vis;
    sx = x1, sy = y1;
    ex = x2, ey = y2;
    init();
    vis.insert({sx, sy});
    int res = dynamical(sx, sy, 0,vis, dp);
    cout << "res = " << res << "\n";
    return res;
}

int main() {
//    std::cout << (solution(0, 0, 1, 1) == 1) << std::endl;
//    std::cout << (solution(0, 0, 2, 1) == 1) << std::endl;
//    std::cout << (solution(0, 0, 3, 3) == 1) << std::endl;
    std::cout << (solution(-3, -2, 2, 1) == 2) << std::endl;

//    set<pair<int, int>> s;
//    s.insert({3,5});
//    s.insert({3,5});
//    cout << s.size() << "\n";
    return 0;
}