//floyd算法,处理无向图,起点为i ,中转点为k,终点为j

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int fee[N][N];
int dp[N][N];

void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "输入站点数量\n";
    cin >> n;
    cout << "输入租金矩阵\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> fee[i][j];
            dp[i][j] = fee[i][j];
        }
    }
    floyd(n);
    cout << dp[1][n] << "\n";
    return 0;
}