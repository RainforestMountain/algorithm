#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string transform(int num, int p) {
    string s;
    while (num > 0) {
        int rem = num % p;
        if (rem < 10) {
            s.insert(s.begin(), '0' + rem);
        } else {
            s.insert(s.begin(), 'A' + (rem - 10));
        }
        num = num / p;
    }
    return s;
}

void solve() {
    int p;
    cin >> p;
    for (int i = 1; i <= p - 1; i++) {
        for (int j = 1; j <= i; j++) {
            cout << transform(i, p) << "*" << transform(j, p) << "=" << transform(i * j, p) << " ";
        }
        cout << "\n";
    }

}
//进制转换
//10进制转移p进制




int main() {
//    cout << tranfrom(13, 16) << "\n";
    solve();
    return 0;
}
