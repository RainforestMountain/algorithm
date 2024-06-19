#include<bits/stdc++.h>
#include <iostream>

using namespace std;

struct supply {
    int p = 0;
    int s = 0;
    int index;
};

bool cmp(supply &o1, supply &o2) {
    return (o1.s + o1.p) < (o2.s + o2.p);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, B;
    cin >> N >> B;
    vector<supply> supplys(N);
    for (int i = 0; i < N; i++) {
        cin >> supplys[i].p >> supplys[i].s;
        supplys[i].index = i;
    }
    sort(supplys.begin(), supplys.end(), cmp);
    int temp = B;
    int i = 0;
    for (; i < N; i++) {
        if (temp <= 0) {
            break;
        }
        temp -= supplys[i].p + supplys[i].s;
    }
    int ans = i - 1;
    if (i == N) {
        cout << N << "\n";
    } else {
        if (temp == 0) {
            temp += supplys[i - 1].p + supplys[i - 1].s;
            ans = ans + ((temp - supplys[i - 1].p / 2 - supplys[i - 1].s - supplys[i].p - supplys[i].s >= 0) ? 1 : 0);
        } else if (temp < 0) {
            temp += supplys[i - 1].p + supplys[i - 1].s;
            ans = ans + ((temp - (supplys[i - 1].p / 2 + supplys[i - 1].s)) >= 0 ? 1 : 0);
        }
        cout << ans << "\n";
    }
    return 0;
}
