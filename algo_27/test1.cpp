#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> array(n + 1);
    array[0] = INT_MAX;
    int first = 1;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
        if (array[i] < array[first]) {
            first = i;
        }
        sum += array[i];
    }
    if (n <= 1) {
        printf("0.00\n");
        return;
    }
    int second = first - 1;
    for (int i = 1; i <= n; i++) {
        if (i != first && array[i] < array[second]) {
            second = i;
        }
    }
    printf("%.2f\n", ((sum - array[first] - array[second]) * 2 + array[first] + array[second]) * 0.5);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //solve();
    cout << "LONG_MAX = " << LONG_MAX << "\n";
    cout << "INT_MAX = " << INT_MAX << "\n";
    cout << "LONG_LONG_MAX = " << LONG_LONG_MAX << "\n";
    return 0;
}
