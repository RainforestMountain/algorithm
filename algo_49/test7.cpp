#include <bits/stdc++.h>

using namespace std;

int solution(std::vector<int> stocks) {
    // Please write your code here
    int n = stocks.size();
    if (n <= 1) {
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(3));
    dp[1][0] = 0, dp[1][1] = -stocks[0], dp[1][2] = 0;
    dp[2][0] = 0, dp[2][1] = max(-stocks[1], -stocks[2]), dp[2][2] = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i])
    }

    return -2;
}

int main() {
    // You can add more test cases here
    std::cout << (solution({1, 2}) == 1) << std::endl;
    std::cout << (solution({2, 1}) == 0) << std::endl;
    std::cout << (solution({1, 2, 3, 0, 2}) == 3) << std::endl;
    std::cout << (solution({2, 3, 4, 5, 6, 7}) == 5) << std::endl;
    std::cout << (solution({1, 6, 2, 7, 13, 2, 8}) == 12) << std::endl;
    return 0;
}