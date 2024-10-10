
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        ll ans = (arr[1] + arr[2]) / 2;

        for (int i = 3; i <= n; i++) {
            ans = (ans + arr[i]) / 2;
        }
        cout << ans << "\n";
    }
}