#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string ans;
    ans.push_back('1');
    for (int i = 0; i < n - 1; i++) {
        ans.push_back('0');
    }
    cout << ans << "\n";
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
