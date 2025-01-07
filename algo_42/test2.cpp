#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<ll>> result;
vector<ll> path;
ll minl = 0x3f3f3f3f;

ll my_gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return my_gcd(b, a % b);
}

// 现在的分子, 分母, 以及上一个1/ x 的分母
void dfs(ll nume, ll deno, ll pre, ll len) {
    if (len >= minl) {
        return;
    }
    if (nume * 1.0 / deno < 1.0 / (10000000)) {
        return;
    }
    ll x = max((ll) ceil(deno * 1.0 / nume), pre + 1);
    ll count = 0;
    while (true) {
        double a = nume * 1.0 / deno;
        double b = 2.0 / x;
        if (nume * 1.0 / deno >= 4.0 / x || 1.0 / x < 1.0 / (10000000) || count > 10000) {
            break;
        }
        if (nume * 1.0 / deno < 1.0 / x) {
            x++;
            continue;
        }
        //分子是
        ll g1 = my_gcd(deno, x);
        ll tn = nume * (x / g1) - deno / g1;
        ll td = deno / g1 * x;
        ll g2 = my_gcd(tn, td);
        tn = tn / g2;
        td = td / g2;
        path.push_back(x);
        if (tn > 1) {
            dfs(tn, td, x, len + 1);
        } else if (tn == 1) {
            if (td > x && (1.0 / td) >= 1.0 / (10000000)) {
                path.push_back(td);
                result.push_back(path);
                path.pop_back();
            }
            minl = min(minl, len + 1);
        }
        path.pop_back();
        x++;
        count++;
    }
}

void solve() {
    ll a, b;
    cin >> a >> b;
    dfs(a, b, 1, 0);
    sort(result.begin(), result.end(), [](auto o1, auto o2) {
        if (o1.size() < o2.size()) {
            return true;
        } else if (o1.size() > o2.size()) {
            return false;
        } else {
            return 1.0 / o1[o1.size() - 1] > 1.0 / o2[o2.size() - 1];
        }
    });
    for (int i = 0; i < result[0].size(); i++) {
        if (i == result[0].size() - 1) {
            cout << result[0][i];
        } else {
            cout << result[0][i] << " ";
        }
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve();

//    cout << (1 * 1.0 / 6 + 1 * 1.0 / 2 == 2.0 / 3) << "\n";

    return 0;
}
