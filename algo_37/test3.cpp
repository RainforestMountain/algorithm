#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> stu(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> stu[i];
    }
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + stu[i];
    }
    //枚举左区间, 得到区间的和 sumL, 然后用treeset获取最接近sumL的右区间的区间和, 要提前使得treeset满足要求, 所有推荐枚举左区间的右断点
    //区间和求解用前缀和

    multiset<ll> rSum;//允许重复元素
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rSum.insert(pre[j] - pre[i - 1]);
        }
    }
    //l1 <= r1 < l2 <= r2
    ll ans = LONG_LONG_MAX;
    for (int r1 = 1; r1 <= n - 1; r1++) {
        //删除以r1为左端点的右区间, 删除和
        for (int r2 = r1; r2 <= n; r2++) {
            ll sum = pre[r2] - pre[r1 - 1];
            if (rSum.find(sum) != rSum.end()) {
                rSum.erase(rSum.find(sum));
            }
        }
        for (int l1 = 1; l1 <= r1; l1++) {
            ll sum = pre[r1] - pre[l1 - 1];
            if (rSum.lower_bound(sum) != rSum.end()) { //返回第一个大于等于sum的元素
                ans = min(ans, abs(*rSum.lower_bound(sum) - sum));
                if (rSum.lower_bound(sum) != rSum.begin()) {
                    //只要lower_bound(k) != s.begin(), 即第一个元素指针位置, 那么就能找到小于等于k的元素
                    ans = min(ans, abs(*(--rSum.lower_bound(sum)) - sum));
                }
            }
        }
    }
    cout << ans << "\n";

}

int main() {

    solve();
//    multiset<int> s = {1, 2, 3, 5, 6};
//    cout << *(--s.lower_bound(0)) << "\n";//小于等于
//    cout << *s.lower_bound(4) << "\n";//大于等于
    return 0;
}

