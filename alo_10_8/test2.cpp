#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin() + 1, arr.end() - 1);
    vector<int> diff(n + 1);
    for (int i = 2; i <= n; i++) {
        diff[i] = arr[i] - arr[i - 1];
    }
    //差分数组的特殊前缀和
    vector<int> prx(n + 1);
    for (int i = 1; i <= n; i++) {
        prx[i] = prx[i - 1] + diff[i];
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int l = i - 1;
        int r = i + 1;

    }

    return 0;
}
