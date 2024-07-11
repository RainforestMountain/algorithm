#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool cmp(int &a, int &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        int count = 5;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        int ret = 1;
        while (count > 0) {
            sort(v.begin(), v.end());
            int ma = v[2];
            int mi = v[0];
            if (mi == 10) {
                break;
            }
            if (ma - mi >= 5) {
                if (mi + 5 > 10) {
                    mi = 10;
                } else {
                    mi = mi + 5;
                }
                v[0] = mi;
                count = 0;
            } else if (ma - mi > 0) {
                count = count - (ma - mi);
                mi = ma;
                v[0] = mi;
            } else {
                v[2] = v[2] + 1;
                count -= 1;
            }
        }
        ret = v[0] * v[1] * v[2];
        cout << ret << "\n";
        t--;
    }

    return 0;
}
