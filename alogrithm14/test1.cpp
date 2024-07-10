#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long gcd(long a, long b) {
    long r = a % b;
    while (r > 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

long lcm(long a, long b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while (t > 0) {

        long a, b;
        cin >> a >> b;
        cout << gcd(a, b) <<" " <<  lcm(a, b) << "\n";
        t--;
    }
    return 0;
}

