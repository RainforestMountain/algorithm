
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200000 + 4;

vector<int> extend_gcd(int a, int b) {
    if (b == 0) {
        return vector<int>{1, 0, a};
    }
    vector<int> res = extend_gcd(b, a % b);
    return vector<int>{res[1], res[0] - a / b * res[1], res[2]};
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ll s = 0;
    ll d = 0;
    ll res1 = 0;
    ll res2 = 0;
    ll midMod = sum % m;
    for (; s <= m; s++) {
        if ((n * s % m + sum) % m < midMod) {
            res1 = s;
            res2 = d;
            midMod = (n * s % m + sum) % m;
        }
        if ((n * s % m + sum) % m == 0) {
            cout << 0 << "\n";
            cout << res1 << " " << res2 << "\n";
            return;
        }
    }
    d = 1;
    s = 0;
    for (; s <= m; s++) {
        if ((n * s %  m + n * (n + 1) / 2 + sum) % m < midMod) {
            res1 = s;
            res2 = d;
            midMod = (n * s  % m + n * (n + 1) / 2 + sum) % m;
        }
        if ((n * s % m + n * (n + 1) / 2 + sum) % m == 0) {
            cout << 0 << "\n";
            cout << res1 << " " << res2 << "\n";
            return;
        }
    }
    cout << midMod << "\n";
    cout << res1 << " " << res2 << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}