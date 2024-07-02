#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int k = 0; k < q; k++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        bool flag = true;

        vector<int> kinds(26);
        int count = 0;
        for (int i = l1 - 1, j = l2 - 1; i <= r1 - 1 && j <= r2 - 1; i++, j++) {
            if (s[i] != s[j]) {
                flag = false;
                kinds[s[i] - 'a']++;
                kinds[s[j] - 'a']++;
            }
        }
        if (flag) {
            cout << 0 << "\n";
            cout << "\n";
        } else {
            for (int i = 0; i < kinds.size(); i++) {
                if (kinds[i] != 0) {
                    count++;
                }
            }
            cout << count << "\n";
            for (int i = 0; i < kinds.size(); i++) {
                if (kinds[i] != 0) {
                    cout << (char) (i + 'a');
                }
            }
            cout << "\n";
        }
    }
}
