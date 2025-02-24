#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    queue<string> vc;
    set<string> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (st.find(s) == st.end()) {
            vc.push(s);
            st.insert(s);
        }
    }
    while (!vc.empty()) {
        cout << vc.front() << "\n";
        vc.pop();
    }
    return 0;
}
