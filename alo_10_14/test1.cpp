#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

int n;

void solve() {
    cin >> n;
    int res = n * (n - 1) / 2 - n + 1;
    res = ceil((double) res / (double) 3);
    cout << res << endl;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = n - i - j;//保证不会与之前的顶点有两两相同的情况
            if (k <= 0) k = k + n;
            if (k > j) cout << i << ' ' << j << ' ' << k << endl;
        }
    }

    // 1 2 3 4 5 1 2 3 4 5
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
