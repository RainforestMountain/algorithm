#include <bits/stdc++.h>

using namespace std;

int solution(std::string dna1, std::string dna2) {
    // Please write your code here
    int n = dna1.size();
    int m = dna2.size();
    //等价于添加,和替换
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // 初始化 dp 数组的第一行和第一列
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dna1[i - 1] == dna2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];//这里不用操作了
            } else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }

    return dp[n][m];
}

int main() {
    // You can add more test cases here
    std::cout << (solution("AGT", "AGCT") == 1) << std::endl;
    std::cout << (solution("", "ACGT") == 4) << std::endl;
    std::cout << (solution("GCTAGCAT", "ACGT") == 5) << std::endl;
    return 0;
}