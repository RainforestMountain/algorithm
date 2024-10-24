
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int ma = 0;
    int mi = INT_MAX;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        ma = max(ma, v);
        mi = min(mi, v);
    }
    cout << (ma - mi) * (n - 1) << "\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}