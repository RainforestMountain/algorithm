#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200000 + 4;

void solve() {
    int n;
    cin >> n;
    unordered_set<string> s;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        bool jude = false;
        for (int j = 1; j <= m; j++) {
            string src;
            cin >> src;
            if (src.find("bie") != std::string::npos && s.find(src) == s.end()) {
                s.insert(src);
                jude = true;
                cout << src << "\n";
            }
        }
        if (!jude) {
            cout << "Time to play Genshin Impact, Teacher Rice!" << "\n";
        }
    }

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