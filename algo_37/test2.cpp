#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int mp[100000 + 2];

void solve() {
    int N;
    cin >> N;
    int ma = 1;
    for (int i = 1; i <= N; i++) {
        int v;
        cin >> v;
        mp[v]++;
        ma = max(ma, v);
    }
    //gcd(a, b, c) = s
    //直接找 a = k1*s , b = k2 * s, c = k3 * s的a,b,c是否存在, 去枚举s
    vector<vector<int>> res;
    for (int i = ma; i >= 1; i--) {
        vector<int> tmp;
        for (int k = 1; k * i <= ma; k++) {
            //相同的可以多次选择
            int count = mp[k * i];
            while (count > 0) {
                tmp.push_back(k * i);
                count--;
            }
            if (tmp.size() >= 3) {
                res.emplace_back(tmp);
//                cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << "\n";
//                return;
            }
        }
    }
    sort(res.begin(), res.end(), [](auto o1, auto o2) {
        if (o1[0] < o2[0]) {
            return true;
        } else if (o1[0] > o2[0]) {
            return false;
        } else {
            if (o1[1] < o2[1]) {
                return true;
            } else if (o1[1] > o2[1]) {
                return false;
            } else {
                return o1[2] < o2[2];
            }
        }
    });
    cout << res[0][0] << " " << res[0][1] << " " << res[0][2] << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}