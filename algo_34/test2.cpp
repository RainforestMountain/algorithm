#include <bits/stdc++.h>

#define endl '\n'
#define int __int128
using namespace std;

/*
t[x]：表示数字 x 在输入中出现的次数
s[x]：表示数字 x 的不同因数的个数（不包括 x 本身）
b[x]：表示数字 x 的倍数的个数
*/
const int N = 1e5 + 5;
const int P = 1e5;
int t[N], s[N], b[N];

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(int x) {
    if (x < 0) {
        putchar('-');
        x *= -1;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    n = read();
    for (int i = 1; i <= n; i++) {
        t[read()]++;
    }

    int ans = 0;
    for (int i = 1; i <= P; i++) {
        if (t[i] == 0) {
            continue;
        }
        for (int j = i * 2; j <= P; j += i) {
            if (t[j] == 0) {
                continue;
            }
            s[j] += t[i];
            b[i] += t[j];
        }
        b[i] += t[i] - 1;
        s[i] += t[i] - 1;
        ans += t[i] * b[i];
    }
    ans *= ans;
    //容斥原理, 和概率论中,求A||B = A + B - A&&B 等价
    //排除的是 A||B, 减去了 (A + B ), 因为是分别算出来的
    //在补上 A && B
    for (int i = 1; i <= P; i++) {
        if (t[i] == 0) {
            continue;
        }
        ans -= (t[i] * b[i] * b[i] + t[i] * s[i] * s[i]);// 减去 i = j, 减去 k = l
        ans += t[i] * b[i]; //补上 i = j && k = l
        ans -= 2 * t[i] * b[i] * s[i]; // 减去 i = l ,  j = k
        ans += t[i] * (t[i] - 1); // 补上 i = l && j = k
    }
    print(ans);
    return 0;
}
