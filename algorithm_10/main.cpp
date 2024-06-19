#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array.begin(), array.end(), cmp);
    unordered_map<int, int> sortmap;
    for (int i = 0; i < n; i++) {
        if (sortmap.find(array[i]) == sortmap.end()) {
            sortmap.insert({array[i], i + 1});
        }
    }
    int m;
    cin >> m;
    cout << sortmap[m] << "\n";
    return 0;
}
