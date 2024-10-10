#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    //加一个x就可以了,可以不断传递加上, 2(4) - > 5(3) , 5(3) -> 8(2), 8(2) - > 11(1), 如果有四个2, 那么5, 8, 11都可以得到
    //最大值只能是n, 0 - n - 1
    //大于n的就不考虑了
    vector<int> freq(n);
    int mi = INT_MAX;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        mi = min(mi, v);
        if (v < n) {
            freq[v]++;
        }
    }
    if (mi > 0) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (freq[i] == 0) {
            cout << i << "\n";
            return;
        } else {
            if (i + x < n) {
                freq[i + x] += freq[i] - 1;
            }
        }
    }
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
