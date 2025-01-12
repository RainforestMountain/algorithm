#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

struct food {
    int label;
    int price;

    food(int label, int price) : label(label), price(price) {}
};
int dp2[1000][1000][1000];

int dfs(int i, int m, ll sum, ll target, vector<int> &like, vector<ll> &fib) {
    int n = like.size();
    if (sum == target) {
        return 1;
    }
    if (i >= n) {
        return 0;
    }
    int ans = 0;
    //不选择
    ans += dfs(i + 1, m, sum, target, like, fib);
    //选择
    //用魔法
    if (sum + fib[like[i]] <= target && m > 0) {
        ans += dfs(i + 1, m - 1, sum + fib[like[i]], target, like, fib);
    }
    if (sum + like[i] <= target) {
        ans += dfs(i + 1, m, sum + like[i], target, like, fib);
    }

    return ans;
}

int solution(int n, int m, int s, std::vector<int> like) {
    int ma = 0;
    for (int i = 0; i < n; i++) {
        ma = max(like[i], ma);
    }
    vector<ll> fib(ma + 1);
    for (int i = 1; i <= ma; i++) {
        if (i == 1) {
            fib[i] = 1;
        } else {
            fib[i] = fib[i - 1] * i;
        }
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(s + 1, -1)));
    int res = dfs(0, m, 0, s, like, fib);
    cout << "res = " << res << "\n";
    return res;
}

int main() {
    //  You can add more test cases here
//    std::vector<int> like1 = {1, 2, 3};
//    std::vector<int> like2 = {1, 1, 1};
//
//    std::cout << (solution(3, 2, 6, like1) == 5) << std::endl;
//    std::cout << (solution(3, 1, 1, like2) == 6) << std::endl;
    vector<int> like3 = {18, 18, 8, 15, 8, 15};
    cout << solution(6, 14, 24, like3) << "\n";


    return 0;
}
