#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    double d;
    cin >> n >> d;
    double ans = d * pow(2, n);
    printf("%.0f\n", ans);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}
