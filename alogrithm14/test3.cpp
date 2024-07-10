#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;//long long 范围更大, 防止越界
const ll mod = 998244353;

long inv(ll a) {
    ll x = a;
    ll b = mod - 2;
    ll ans = 1;
    while (b > 0) {
        if ((b & 1 )== 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        b = b >> 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t > 0) {
        ll a, b, c, q;
        cin >> a >> b >> c >> q;
        while (q > 0) {
            ll x;
            cin >> x;
            ll ret = (((a * x % mod + b) % mod) * (inv(c * x % mod) % mod)) % mod;
            cout << ret << "\n";
            q--;
        }
        t--;
    }
    return 0;
}
