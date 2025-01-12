
#include <bits/stdc++.h>

using namespace std;

const int N = 10e5 + 3;
int arr[N];
int dp[N];
map<int, int> multiple;
////这种解法不全面,全靠数据量不大
//void solve() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> arr[i];
//    }
//    int res1 = 0;
//    //以arr[1]为起始
//    dp[1] = dp[2] = arr[1];
//    for (int i = 3; i <= n; i++) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    for (int i = 1; i <= n; i++) {
//        if (dp[i] != arr[i]) {
//            res1++;
//        }
////        cout << dp[i] << " ";
//    }
////    cout << "\n";
//    //以arr[2]为起始
//    int res2 = 0;
//    dp[1] = dp[2] = arr[2];
//    for (int i = 3; i <= n; i++) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    for (int i = 1; i <= n; i++) {
//        if (dp[i] != arr[i]) {
//            res2++;
//        }
////        cout << dp[i] << " ";
//    }
////    cout << "\n";
//    if (arr[3] % 2 == 0) {
//        int res3 = 0;
//        dp[1] = dp[2] = arr[3] / 2;
//        for (int i = 3; i <= n; i++) {
//            dp[i] = dp[i - 1] + dp[i - 2];
//        }
//        for (int i = 1; i <= n; i++) {
//            if (dp[i] != arr[i]) {
//                res3++;
//            }
////        cout << dp[i] << " ";
//        }
//        res1 = min(res1, res3);
//    }
//    cout << min(res1, res2) << "\n";
//
//}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    //整体上看
    //数列会变成k倍的以一开始的斐波那契数列
    // arr[i] 得被f(i)整除, k = arr[i] / f[i], arr[i] % f[i] == 0
    //那么倍数最多的k, k倍斐波那契数列项出现的多, 那么修改就会少一些
    // 2 2 4 7 10 8
    // 1 1 2 3 5 8 (正确1倍的斐波那契数列)
    // k 为2的斐波那契数列项有 2 2 4 10
    // k为1的只有 8
    // 找到出现次数最多的倍数k, 就能让修改最少了
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] % dp[i] == 0) {
            multiple[arr[i] / dp[i]]++;
        }
    }
    int res = 0x3f3f3f3f;
    for (const auto &kv: multiple) {
        res = min(res, n - kv.second);
    }
    cout << res << "\n";

}

int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}