#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        vector<int> v(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int count = 0;
        for (int i = 1; i < k; i++) {
            if (v[i] != 1) {
                count = count +  v[i] - 1 + v[i];
            } else {
                count++;
            }
        }
        cout << count << "\n";
        t--;
    }
    return 0;
}
