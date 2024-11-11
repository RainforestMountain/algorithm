#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    ll n = 10000;
    for (ll y = 1; y <= n; y++) {
        for (ll x = 1; x <= y; x++) {
            if ((x * x + y * y) % (x * y + 1) == 0) {
                cout << x << " " << y << "\n";
            }
        }
    }


    return 0;
}
