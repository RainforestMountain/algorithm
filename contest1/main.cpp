#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 10e5 + 1;


struct op {
    int l;
    int r;
};

bool cmp(op &o1, op &o2) {
    return o1.l > o2.r;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<op> array(n + 1);
    for (int i = 0; i < n; i++) {

    }
    return 0;
}
