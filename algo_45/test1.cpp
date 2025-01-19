#include <bits/stdc++.h>
#include <vector>

using namespace std;
//多重背包
//直接拆分
int solution(int Q, int V, vector<vector<int>> ships) {
    // Please write your code here
    vector<int> dp(V + 1, 0);//预算为k的最大载货量

    for (int i = 0; i < Q; i++) {//前Q种类型的船
        for (int j = 1; j <= ships[i][0]; j++) {//一种类型有m[i]的数量, 最少为1
            for (int k = V; k >= ships[i][1]; k--) {//dp[k] for了每种的m[i]次数,
                //会累加, 倒序是表示, 拆分的物品只选一次
                //预算[V .. v[i]], 小于v[i]其实就是dp[k] = dp[k] ,没有什么特别的变化
                //选和不选
                dp[k] = max(dp[k], dp[k - ships[i][1]] + ships[i][2]);
            }
        }
    }
    //结果是预算不超过V的最大载货量
    int ans = 0;
    for (int i = 1; i <= V; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    // You can add more test cases here
    vector<vector<int>> ships = {{2, 3, 2}, {3, 2, 10}};
    vector<vector<int>> ships2 = {{30, 141, 47}, {9, 258, 12}, {81, 149, 13}, {91, 236, 6}, {27, 163, 74}, {34, 13, 58}, {61, 162, 1}, {80, 238, 29}, {36, 264, 28}, {36, 250, 2}, {70, 214, 31}, {39, 116, 39}, {83, 287, 4}, {61, 269, 94}, {23, 187, 46}, {78, 33, 29}, {46, 151, 2}, {71, 249, 1}, {67, 76, 85}, {72, 239, 17}, {61, 256, 49}, {48, 216, 73}, {39, 49, 74}};
    cout << (solution(2, 10, ships) == 32) << endl;
    cout << (solution(23, 400, ships2) == 1740) << endl;

    return 0;
}
