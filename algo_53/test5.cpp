
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, const std::vector<int> &b, const std::vector<int> &c) {
    // Edit your code here
    int maxV = 0;
    for (int i = 0; i < n; i++) {
        maxV = max(maxV, b[i]);
    }
    vector<bool> access(maxV + maxV + 1);
    vector<int> upgrade(maxV + maxV + 1, 0x3f3f3f3f);
    access[1] = true;
    upgrade[1] = 0;
    for (int i = 1; i <= maxV; i++) {
        if (access[i]) {
            for (int x = 1; x <= i; x++) {
                access[i + i / x] = true;
                if (upgrade[i] < 0x3f3f3f3f) {
                    upgrade[i + i / x] = min(upgrade[i] + 1, upgrade[i + i / x]);
                }
            }
        }
    }
    //背包问题, 选择i个英雄去升级, 升级总次数需要小于等于k, 的最大奖励值,
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));//dp[i][j] 前i个英雄选择, 升级总次数不超过k的最大奖励值
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (upgrade[b[i - 1]] < 0x3f3f3f3f && j >= upgrade[b[i - 1]]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - upgrade[b[i - 1]]] + c[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    // Add your test cases here
    std::cout << (solution(4, 4, {1, 7, 5, 2}, {2, 6, 5, 2}) == 9) << std::endl;
    std::cout << (solution(3, 0, {3, 5, 2}, {5, 4, 7}) == 0) << std::endl;
    std::cout << (solution(3, 3, {3, 5, 2}, {5, 4, 7}) == 12) << std::endl;
    return 0;
}
