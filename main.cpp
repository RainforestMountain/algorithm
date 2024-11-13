#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200000 + 4;

ll arr[N];
ll t[4 * N];
ll lz[4 * N];

void push(int s, int e, int x);

void buildTree(int s, int e, int x);

void pushUp(int x) {
    t[x] = t[x << 1] + t[x << 1 | 1];
}

void buildTree(int s, int e, int x) {
    if (s == e) {
        t[x] = arr[s];
        return;
    }
    int mid = e + ((s - e) >> 1);
    buildTree(s, mid, x << 1);
    buildTree(mid + 1, e, x << 1 | 1);
//    t[x] = t[x << 1] + t[x << 1 | 1];
    pushUp( x);
}

void pushDown(int s, int e, int x) {
    if (lz[x] == 0) {
        return;
    }
    int mid = e + ((s - e) >> 1);
    int lx = x << 1;
    int rx = x << 1 | 1;
    //lz下拉时把左右孩子权值更新了
    //t[x] += lz[x] * (s - e + 1); 这个添加lz时终端节点会加上
    t[lx] += lz[x] * (mid - s + 1);
    t[rx] += lz[x] * (e - (mid + 1) + 1);
    lz[lx] += lz[x];
    lz[rx] += lz[x];
    lz[x] = 0;
}


void add(int l, int r, ll val, int s, int e, int x) {
    if (s >= l && e <= r) {
        //在目标区间内, 添加懒标记, 更新权值
        t[x] += val * (e - s + 1);
        lz[x] += val;
        return;
    }
    //往下走要下拉, 因为之前add时这个节点lz标记有的还不是0, 重新让终端节点之前的节点变正确
    pushDown(s, e, x);
    int mid = e + ((s - e) >> 1);
    //[l, r]
    //  [s, mid]
    if (s <= r && mid >= l) {//左区间有交集, 继续往下
        add(l, r, val, s, mid, x << 1);
    }
    if (e >= l && mid + 1 <= r) {
        add(l, r, val, mid + 1, e, x << 1 | 1);
    }
    //由于终端节点往上有的权值没有更新, 上拉
    pushUp(x);
}

ll query(int l, int r, int s, int e, int x) {
    if (s >= l && e <= r) {
        return t[x];
    }
    ll res = 0;
    pushDown(s, e, x);
    int mid = e + ((s - e) >> 1);
    //[l, r]
    //  [s, mid]
    if (s <= r && mid >= l) {//左区间有交集, 继续往下
        res += query(l, r, s, mid, x << 1);
    }
    if (e >= l && mid + 1 <= r) {
        res += query(l, r, mid + 1, e, x << 1 | 1);
    }
    pushUp( x);
    return res;
}


void solve() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    buildTree(1, n, 1);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            int val;
            cin >> val;
            add(l, r, val, 1, n, 1);
        } else {
            cout << query(l, r, 1, n, 1) << "\n";
        }
    }
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int k = 1;
//    cin >> t;
    while (k--) {
        solve();
    }
    return 0;
}
