#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 998244353;

ll extent_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {//a * x + 0 * y = gcd(a, 0) = a;
        x = 1;
        y = 0;
        return a;
    }
    extent_gcd(b, a % b, x, y);
    ll tx = x;
    ll ty = y;
    x = ty;
    y = tx - a / b * ty;
    return a;
}


//ll inv(ll a) {
//    ll x = 0;
//    ll y = 0;
//    ll tmp = extent_gcd(mod, a, x, y);
//    return (y % mod + mod) % mod;
//}


//快速幂

ll qmi(ll a, int x) {
    ll ans = 1;
    while (x > 0) {
        if ((x & 1) == 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<bool> jude(n + 1);//不是合数
    vector<ll> inv(n + 1);
    inv[1] = 1;
    ll lcm = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        if (!jude[i]) {
            for (int k = 2; i * k <= n; k++) {
                jude[i * k] = true;
            }
            lcm = lcm * qmi(i, (int) (log(n) / log(i))) % mod;
        }
    }

    // 求和 lcm / i * (n - 2 * i + 1) % mod
    cout << "lcm = " << lcm << "\n";
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans % mod + lcm * inv[i] % mod * (n - 2 * i + 1) % mod + mod) % mod;
    }
    cout << ans % mod << "\n";


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
