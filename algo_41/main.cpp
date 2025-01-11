#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> result;


void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> square;
    for (int k = 1; k * k <= b / 2; k++) {
        square.push_back(k * k);
    }
    vector<int> res;
    int low = (int) log10(a) + 1;
    int high = (int) log10(b) + 1;
    for (int i = 0; i < square.size(); i++) {
        for (int j = 0; j < square.size(); j++) {
            int l1 = (int) log10(square[i]) + 1;
            int l2 = (int) log10(square[j]) + 1;
            if (l1 + l2 > high) {
                break;
            }
            //内部没有前导0

            int sum = square[i] * (int) pow(10, l2) + square[j];
            if (sum >= a && sum <= b && ((int) sqrt(sum)) * ((int) sqrt(sum)) == sum) {
                res.push_back(sum);
            }
            //内部有前导0
            for (int k = 1; l1 + k + l2 <= high; k++) {
                int sum = square[i] * (int) pow(10, l2 + k) + square[j];
                if (sum >= a && sum <= b && ((int) sqrt(sum)) * ((int) sqrt(sum)) == sum) {
                    res.push_back(sum);
                }
            }
        }
    }
    std::sort(res.begin(), res.end());
    for (const auto &item: res) {
        cout << item << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
