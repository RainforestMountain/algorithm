
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1' || s[s.size() - 1] == '1') {
        cout << "YES" << "\n";
        return;
    }
    for (int i = 2; i < s.size(); i++) {
        if (s[i] == s[i - 1] && s[i] == '1') {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";

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