#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long a, b, c;
        cin >> a >> b >> c;
        long x = a;
        long ans = 1;
        while (b != 0) {
            if ((b & 1) == 1) {
                ans = ans * x % c;
            }
            x = (x * x) % c;
            b = b >> 1;
        }
        cout << ans << "\n";
    }
    return 0;
}