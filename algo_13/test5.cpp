#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    vector<int> arr(n + 1);
    vector<char> s(n + 1);
    set<int> bad;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R') {//需要交换
            bad.insert(i);
        }
    }
    while (q--) {

    }


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

