#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Time {
    int s;
    int e;
    int l;
    int ack = 0;//最小确认开始下降时间点

    Time() {}

    Time(int s, int e, int l) : s(s), e(e), l(l) {}
};

void solve() {
    int n;
    cin >> n;
    vector<Time> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int t, d, l;
        cin >> t >> d >> l;
        v[i] = Time(t, t + d, l);
    }
    sort(v.begin() + 1, v.end(), [](auto o1, auto o2) {
        if (o1.e < o2.e) {
            return true;
        } else if (o1.e > o2.e) {
            return false;
        } else {
            return o1.s < o2.s;
        }
    });
    v[1].ack = v[1].s;
    for (int i = 1; i < n; i++) {
        if (v[i].ack + v[i].l > v[i + 1].e && v[i + 1].s + v[i + 1].l ) {
            cout << "NO\n";
            return;
        }
        v[i + 1].ack = max(v[i + 1].s, v[i].ack + v[i].l);
    }
    if (v[n].ack > v[n].e) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
