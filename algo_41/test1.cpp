#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 530;

int dp[N][N];//dp[i][t] 插入第i个数字,后折点为t表示为dp[i][t]

const int mod = 123456;

void solve1() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 2 << "\n";
        return;
    }
    dp[1][0] = 1;
    for (int i = 2; i < n; i++) {
        dp[i][0] = 2;
    }
    for (int i = 2; i < n; i++) {
        for (int t = 0; t <= k - 1 && t <= i; t++) {
            if (t > 0) {
                dp[i + 1][t] = (dp[i + 1][t] + dp[i][t] * (t + 1)) % mod;
            }
            dp[i + 1][t + 1] = (dp[i + 1][t + 1] + dp[i][t] * 2) % mod;
            dp[i + 1][t + 2] = (dp[i + 1][t + 2] + dp[i][t] * (i + 1 - (t + 1) - 2)) % mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t <= k - 1; t++) {
            cout << dp[i][t] << " ";
        }
        cout << "\n";
    }
    cout << dp[n][k - 1] % mod << "\n";

}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 2 << "\n";
        return;
    }
    dp[1][0] = 1;
    for (int i = 2; i < n; i++) {
        dp[i][0] = 2;
    }
    for (int i = 3; i <= n; i++) {
        for (int t = 1; t <= k - 1 && t <= i; t++) {
            //没有变化的情况, 有t - 1种
            dp[i][t] = (dp[i][t] + dp[i - 1][t] * (t + 1)) % mod;//已经有的节点数大于等于3才有波峰
            //多加了一种
            dp[i][t] = (dp[i][t] + dp[i - 1][t - 1] * 2) % mod;
            //多加了两种
            if (t >= 2) {
                //只有(t - 2) /2个波峰
                dp[i][t] = (dp[i][t] + dp[i - 1][t - 2] * (i - (t - 1) - 2)) % mod;
            }


        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int t = 0; t <= k - 1; t++) {
//            cout << dp[i][t] << " ";
//        }
//        cout << "\n";
//    }
    cout << dp[n][k - 1] % mod << "\n";

}


int main() {
    //int arr[501][501][501];
    solve();

    return 0;
}


//#include <bits/stdc++.h>
//
//#define ll long long
//#define setp setprecision
//#define mem(a, m) memset(a, m, sizeof(a))
//using namespace std;
//
//const int MOD = 123456;
//int n, k;
//int dp[505][505];
//
//int mod(int a) {
//    return a % MOD;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin >> n >> k;
//    dp[1][0] = 1;
//    for (int i = 2; i < n; i++) {
//        dp[i][0] = 2;
//        for (int j = 0; j <= i; j++) {
//            dp[i + 1][j] += mod(dp[i][j] * (j + 1));
//            dp[i + 1][j + 1] += mod(dp[i][j] * 2);
//            dp[i + 1][j + 2] += mod(dp[i][j] * (i - j - 2));
//        }
//    }
//    cout << dp[n][k - 1] % MOD;
//    return 0;
//}