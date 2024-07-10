#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 10e6 + 2;
int prime[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (prime[i] != 1) {
            int k = 2;
            while (k * i <= n) {
                prime[k * i] = 1;
                k++;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            cout << i << " ";
        }
    }
    cout << "\n";

    return 0;
}
