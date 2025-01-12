#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 10e9 + 1;

ll mo(ll x) {
    return (x % mod + mod) % mod;
}

int solution(int n, std::vector<int> a, std::vector<int> b) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    //可以整除即取模为0, 还有求组合数,每个位置选不选,  尽快联想到动态规划
    //动态规划数组：定义一个二维数组 f，
    //其中 f[i][j] 表示前 i 张卡牌选择后，和模3为 j 的方案数。
    vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
    dp[1][a[0] % 3]++;
    dp[1][b[0] % 3]++;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            int t1 = (3 - (a[i - 1] - j) % 3) % 3;
            int t2 = (3 - (b[i - 1] - j) % 3) % 3;
            dp[i][j] = dp[i - 1][(3 - (a[i - 1] - j) % 3) % 3] + dp[i - 1][(3 - (b[i - 1] - j) % 3) % 3];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "res = " << dp[n][0] << "\n";
    return dp[n][0]; // Placeholder return
}

int main() {
//    std::cout << (solution(3, {1, 2, 3}, {2, 3, 2}) == 3) << std::endl;
//    std::cout << (solution(4, {3, 1, 2, 4}, {1, 2, 3, 1}) == 6) << std::endl;
    std::cout << (solution(5, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}) == 32) << std::endl;
    return 0;
}
