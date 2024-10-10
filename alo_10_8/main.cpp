#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n - m; i++) {
        int v;
        cin >> v;
        sum += v;
    }
    double mi = (sum + m * 1) * 1.0 / n;
    double ma = (sum + m * 5) * 1.0 / n;
    printf("%.5f %.5f\n", mi, ma);
    return 0;
}
