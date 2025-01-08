#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

int dynamical(int i, int n, int p, set<int> &vis, int free) {
    if (i >= n) {
        result.push_back(vector<int>(path));
        return 1;
    }
    int ans = 0;
    if (free == 1) {
        for (int cur = 1; cur <= n; cur++) {
            vis.insert(cur);
            path.push_back(cur);
            ans += dynamical(i + 1, n, cur, vis, 0);
            vis.erase(cur);
            path.pop_back();
        }
    } else {
        for (int cur = 1; cur <= n; cur++) {
            if (vis.find(cur) == vis.end() && p * cur % 2 == 0) {
                vis.insert(cur);
                path.push_back(cur);
                ans += dynamical(i + 1, n, cur, vis, 0);
                vis.erase(cur);
                path.pop_back();
            }
        }
    }

    return ans;
}

int solution(int n) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    set<int> vis;
    int res = dynamical(0, n, 0, vis, 1);
    cout << "res = " << res << "\n";
    return res;
}

int main() {
    // std::cout << (solution(2) == 2) << std::endl;
    // std::cout << (solution(3) == 2) << std::endl;
    std::cout << (solution(5) == 12) << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}