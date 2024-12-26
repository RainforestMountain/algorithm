#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve1() {
//    int n;
//    cin >> n;
    vector<int> array(2 * 10e5 + 1);
    for (int i = 1; i <= 2 * 10e5; i++) {
        array[i] = i;
    }

    for (int i = 1; i < array.size(); i++) {
        if (array[i] % 2 == 1) {
            continue;
        }
        bool flag = false;
        for (int j = 2; j <= array[i] / 2; j++) {
            if ((2 * array[i] - j * j - j) % (2 * j) == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << array[i] << " ";
        }
    }
    cout << "\n";
}

ll lowbit(ll n) {
    return n & (-n);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> array(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (array[i] == lowbit(array[i])) {
            count++;
        }
    }
    cout << count << "\n";
}


int main() {
    solve();
    return 0;
}
