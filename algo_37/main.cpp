#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


//len 已经有的长度, 前导0也算了
ll dfs(int len, int base, int offset, int n, int free, int fix) {
    if (len >= n) {
        return 1;
    }
    int cur = (base / offset) % 10;
    ll ans = 0;
    if (fix == 0) {//前面没选过
        if (free == 0) {
            for (int i = 1; i <= cur; i++) {
                if (i == cur && (n - len + i) % 2 == 0) {
                    ans += dfs(len + 1, base, offset / 10, n, 0, 1);
                }
                if (i < cur && (n - len + i) % 2 == 0) {
                    ans += dfs(len + 1, base, offset / 10, n, 1, 1);
                }
            }
            //还可以选0
            ans += dfs(len + 1, base, offset / 10, n, 1, 0);//已经小了,可以自由选
        } else {
            if ((n - len) % 2 == 0) {
                for (int i = 2; i <= 8; i += 2) {
                    ans += dfs(len + 1, base, offset / 10, n, 1, 1);
                }
                //还可以选0
            } else {
                for (int i = 1; i <= 9; i += 2) {
                    ans += dfs(len + 1, base, offset / 10, n, 1, 1);
                }
            }
            ans += dfs(len + 1, base, offset / 10, n, 1, 0);
        }
    } else {//前面选过了
        if (free == 0) {
            for (int i = 0; i <= cur; i++) {
                if (i == cur && (n - len + i) % 2 == 0) {
                    ans += dfs(len + 1, base, offset / 10, n, 0, 1);
                }
                if (i < cur && (n - len + i) % 2 == 0) {
                    ans += dfs(len + 1, base, offset / 10, n, 1, 1);
                }
            }
        } else {
            if ((n - len) % 2 == 0) {
                for (int i = 0; i <= 8; i += 2) {
                    ans += dfs(len + 1, base, offset / 10, n, 1, 1);
                }
            } else {
                for (int i = 1; i <= 9; i += 2) {
                    ans += dfs(len + 1, base, offset / 10, n, 1, 1);
                }
            }
        }
    }
    return ans;
}

void solve() {
    int N;
    cin >> N;
    int digits = 0;
    int offset = 1;
    int tmp = N;
    while (tmp > 0) {
        tmp /= 10;
        digits++;
        offset *= 10;
    }
    //还没有小,不能自由选,而且前面也没选, 最后一个0也选了,要减去
    cout << dfs(0, N,  offset / 10, digits, 0, 0) - 1 << "\n";
}

bool isfine(int i) {
    int digit = 1;
    while (i > 0) {
        int v = i % 10;
        if ((v + digit) % 2 == 1) {
            return false;
        }
        i /= 10;
        digit++;
    }
    return true;
}

void solve1(int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (isfine(i)) {
            count++;
//            cout << i << " ";
        }
    }
    cout << "\nforce: " << count << "\n";

}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//    cout << (25 * 49 - 21) << "\n";
//    cout << 233333 * 1.0 / 343720 << "\n";
    solve1(100000);
    solve();
    return 0;
}
