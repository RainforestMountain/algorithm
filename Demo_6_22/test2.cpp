#include<bits/stdc++.h>
#include <iostream>

using namespace std;
const int mod = 998244353;
const long N = 10000007;

int newlog(int a, int b) {
    return int(log(b) / log(a));
}

long long fastVeil(long long a, int k) {
    long long ans = 1;
    long long x = a;
    while (k > 0) {
        if ((k & 1) == 1) {
            ans = ans * x % mod;
        }
        k = k >> 1;
        x = x * x % mod;
    }
    return (int) ans;
}

long long inv[N];

void getInv() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    long long lcm = 1;
    vector<int> p(n + 1);
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (p[i] == 0) {
            for (int k = 2; k <= newlog(i, n) + 1; k++) {
                if (k * i <= n) {
                    p[k * i] = 1;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] == 0) {
            lcm = lcm * fastVeil(i, newlog(i, n)) % mod;
        }
    }

    cout << lcm << "\n";
    getInv();
    //逆元
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long temp = (lcm % mod) * inv[i];
        ans += ((n - 2 * i + 1) * temp) % mod;
    }
    cout << ans << "\n";
    return 0;
}
