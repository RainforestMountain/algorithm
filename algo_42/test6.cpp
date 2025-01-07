#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static int N = 0;

//异或和
static int len = 0;

class SegmentTree {
private:
    vector<ll> sum;
    vector<ll> lazy;
public:
    SegmentTree(vector<ll> &array) {
        sum = vector<ll>(4 * len);
        lazy = vector<ll>(4 * len);
        buildTree(1, 1, len, array);
    }

    //左右根的形式递归建立子树
    void buildTree(int root, int l, int r, vector<ll> &array) {
        if (l == r) {
            sum[root] = array[l];
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(root << 1, l, mid, array);
        buildTree(root << 1 | 1, mid + 1, r, array);
        push_up(root);//左右子树已经建立好了, 然后再建立根
    }

    void update(int a, int b, int x, int l = 1, int r = len, int root = 1) {
        if (a <= l && r <= b) {
            //奇数个异或,等价于一个
            if ((r - l + 1) % 2 == 1) sum[root] ^= x;
            lazy[root] ^= x;
            return;
        }
        int mid = (l + r) >> 1;
        //破坏了lazy了
        push_down(root, l, r);
        //有交错才会更新
        if (a <= mid) {
            update(a, b, x, l, mid, root << 1);
        }
        if (b > mid) {
            update(a, b, x, mid + 1, r, root << 1 | 1);
        }
        //由于递归时不更新,上面节点是旧的, 那么需要向上更新
        push_up(root);
    }

    ll query(int a, int b, int l = 1, int r = len, int root = 1) {
        if (a <= l && r <= b) {
            return sum[root];
        }
        int mid = (l + r) >> 1;
        //破坏lazy
        push_down(root, l, r);
        ll res = 0;
        //交错才查询
        //左区间
        if (a <= mid) {
            res ^= query(a, b, l, mid, root << 1);
        }
        //右区间
        if (b > mid) {
            res ^= query(a, b, mid + 1, r, root << 1 | 1);
        }
        //查询上面的节点不是旧的,没有更新
        return res;
    }

    void push_up(int root) {
        sum[root] = sum[root << 1] ^ sum[root << 1 | 1];
    }

    //向下即孩子节点传递lazy, 变化,同时孩子节点的异或和也要变化
    void push_down(int root, int l, int r) {
        lazy[root << 1] ^= lazy[root];
        lazy[root << 1 | 1] ^= lazy[root];
        int mid = (l + r) >> 1;
        if ((mid - l + 1) % 2 == 1) {
            sum[root << 1] ^= lazy[root];
        }
        if ((r - (mid + 1) + 1) % 2 == 1) {
            sum[root << 1 | 1] ^= lazy[root];
        }
        lazy[root] = 0;//0 ^ x = x
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    len = n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    SegmentTree tree = SegmentTree(arr);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            tree.update(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.query(l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    //cout << (1^3) << "\n";
    return 0;
}