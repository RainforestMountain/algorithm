<<<<<<< HEAD
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    if (q == 0) {
        vector<int> arr1(n);
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        vector<int> counts(n + 1);
        vector<int> arr2(n);
        int j = 0;
        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;
            if (counts[v] == 0) {
                counts[v]++;
                arr2[j] = v;
                j++;
            }
        }
        for (int i = 0; i < j; i++) {
            if (arr2[i] != arr1[i]) {
                cout << "TIDAK" << "\n";
                return;
            }
        }
        cout << "YA" << "\n";
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

=======
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    if (q == 0) {
        vector<int> arr1(n);
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        vector<int> counts(n + 1);
        vector<int> arr2(n);
        int j = 0;
        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;
            if (counts[v] == 0) {
                counts[v]++;
                arr2[j] = v;
                j++;
            }
        }
        for (int i = 0; i < j; i++) {
            if (arr2[i] != arr1[i]) {
                cout << "TIDAK" << "\n";
                return;
            }
        }
        cout << "YA" << "\n";
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

>>>>>>> 287ed1cf6f14d333f9f42b8671d471175f848a62
