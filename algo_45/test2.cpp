#include <bits/stdc++.h>
#include <vector>

using namespace std;
//多重背包
//二进制去拆分

int getP(int ci) {//拆分为p + 2个物品, 找到p , ci >= 2 ^(p + 1) - 1,找到最大的p
    return (int) (log2(ci + 1) - 1);
}

int solution(int Q, int V, vector<vector<int>> ships) {
    // Please write your code here
    vector<int> dp(V + 2, 0);//预算为k的最大载货量

    for (int i = 0; i < Q; i++) {//前Q种类型的船
        int p = getP(ships[i][0]);
        //2^0 ... 2 ^p 这个p + 1个复合物品
        //复合物品, 成本和载货量都要乘上相应的系数
        for (int j = 1; j <= ships[i][0]; j *= 2) {
            if (j <= pow(2,p)) {//2^0 ...2^p 这个p + 1个
                for (int k = V; k >= ships[i][1] * j; k--) {
                    dp[k] = max(dp[k], dp[k - ships[i][1] * j] + ships[i][2] * j);
                }
            } else {
                //最后一个(ci - (2 ^(p + 1) + 1)) 复合物品
                int ri = ships[i][0] - (int) (pow(2, p + 1) - 1);//ri = ci - (2^(p + 1) - 1) 等比数列求和
                if (ri > 0) {
                    for (int k = V; k >= ships[i][1] * ri && k >= 0; k--) {
                        dp[k] = max(dp[k], dp[k - ships[i][1] * ri] + ships[i][2] * ri);
                    }
                }
            }
        }
    }
    //结果是预算不超过V的最大载货量
    int res = 0;
    for (int i = 1; i <= V; i++) {
        res = max(res, dp[i]);
    }
    cout << "ans = " << res << "\n";
    return res;
}

int main() {
    // You can add more test cases here
    vector<vector<int>> ships = {{2, 3, 2},
                                 {3, 2, 10}};
    vector<vector<int>> ships2 = {{30, 141, 47},
                                  {9,  258, 12},
                                  {81, 149, 13},
                                  {91, 236, 6},
                                  {27, 163, 74},
                                  {34, 13,  58},
                                  {61, 162, 1},
                                  {80, 238, 29},
                                  {36, 264, 28},
                                  {36, 250, 2},
                                  {70, 214, 31},
                                  {39, 116, 39},
                                  {83, 287, 4},
                                  {61, 269, 94},
                                  {23, 187, 46},
                                  {78, 33,  29},
                                  {46, 151, 2},
                                  {71, 249, 1},
                                  {67, 76,  85},
                                  {72, 239, 17},
                                  {61, 256, 49},
                                  {48, 216, 73},
                                  {39, 49,  74}};
    cout << solution(2, 10, ships) << "\n";
    cout << (solution(23, 400, ships2) == 1740) << endl;
    vector<vector<int>> ship = {{10, 5, 50}};
    cout << solution(1, 100, ship) << "\n";
    return 0;
}
