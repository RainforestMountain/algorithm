#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;
        int digit = std::to_string(n).size();
        string s;
        for (int i = 0; i < 20; i++) {
            s.append(std::to_string(n));
        }
        vector<vector<ll>> v;
        bool flag = true;

        for (int i = 1; i <= s.size(); i++) {
            if (!flag) {
                break;
            }
            std::stringstream ss(s.substr(0, i));
            ll val = 0;
            ss >> val;
            if (val > 10000000) {
                break;
            }
            ll left = 0;
            ll right = val;
            while (left <= right) {
                ll a = left + (right - left) / 2;
                ll b = n * a - val;
                if (b > 0 && a > 0 && a * digit - b == i) {
                    if (a > 10000) {
                        flag = false;
                    } else {
                        v.push_back(vector<ll>({a, b}));
                    }
                    break;
                } else if (b <= 0 || a * digit - b > i) {
                    left = a + 1;
                } else {
                    right = a - 1;
                }
            }
        }

        cout << v.size() << "\n";
        for (const auto &item: v) {
            cout << item[0] << " " << item[1] << "\n";
        }
        t--;
    }
    return 0;
}
