//#include <iostream>
//#include <bits/stdc++.h>
//
//using namespace std;
//using ll = long long;
//
////最值线段树
//class SegmentTree {
//private:
//    vector<char> cover;//叶子节点,存着字符
//    vector<vector<char>> lazy;//这个区间的每个字符被覆盖成了哪个字符, 离线覆盖,最后查询
//public:
//
//    SegmentTree(string &s) {
//        int N = s.size() - 1;
//        cover = vector<char>(4 * N);
//        lazy = vector<vector<char>>(4 * N, vector<char>(26));
//        buildTree(1, N, s, 1);
//    }
//
//    void buildTree(int l, int r, string s, int root) {
//        if (l == r) {
//            cover[root] = s[l];
//            return;
//        }
//        for (int i = 0; i < 26; i++) {
//            lazy[root][i] = i + 'a';
//        }
//        int mid = (l + r) >> 1;
//        buildTree(l, mid, s, root << 1);
//        buildTree(mid + 1, r, s, root << 1 | 1);
//        //    //向上更新, 这里不用了,因为没有在线查询, 只有最后一次查询
//    }
//
//    void update(int a, int b, char x, char y, int l, int r, int root = 1) {
//        if (a <= l && r <= b) {
//            for (int i = 0; i < 26; i++) {
//                if (lazy[root][i] == x) {//这个地方字符是x要换成y
//                    lazy[root][i] = y;
//                }
//            }
//            return;
//        }
//        push_down(root);
//        int mid = (l + r) >> 1;
//        if (a <= mid) {
//            update(a, b, x, y, l, mid, root << 1);
//        }
//        if (b > mid) {
//            update(a, b, x, y, mid + 1, r, root << 1 | 1);
//        }
//    }
//
//    //最后的结果,离线统计, 把lazy, push_down到底, 然后在把叶子节点的字符给换了
//    void query(int a, int b, int l, int r, int &n, string &res, int root = 1) {
//        //最左下角那个下标是
//        if (l == r) {
//            if (lazy[root][cover[root] - 'a'] >= 'a' && lazy[root][cover[root] - 'a'] <= 'z') {
//                res.push_back(lazy[root][cover[root] - 'a']);
//            } else {
//                res.push_back(cover[root]);
//            }
//            return;
//        }
//        push_down(root);
//        int mid = (l + r) >> 1;
//        query(a, b, l, mid, n, res, root << 1);
//        query(a, b, mid + 1, r, n, res, root << 1 | 1);
//    }
//
//    void all_push_down(int l, int r, int root) {
//        if (l == r) {
//            cover[root] = lazy[root][cover[root] - 'a'];
//            return;
//        }
//        push_down(root);
//        int mid = (l + r) >> 1;
//        all_push_down(l, mid, root << 1);
//        all_push_down(mid + 1, r, root << 1 | 1);
//    }
//
////    void push_up(int root, int l, int r) {
////        int
////        for (int i = l;)
////    }
//
//    //标记变化值向下传递,孩子标记受到影响 + x, 最值也会受到影响, 都加x, 这个逻辑很关键
//    void push_down(int root) {
//        for (int i = 0; i < 26; i++) {
//            lazy[root << 1][i] = lazy[root][i];
//            lazy[root << 1 | 1][i] = lazy[root][i];
//            lazy[root][i] = i + 'a';//复原
//        }
//
//    }
//};
//
//void solve() {
//    string s;
//    cin >> s;
//    int n = s.size();
//    s.insert(s.begin(), '0');
//    int m;
//    cin >> m;
//    SegmentTree tree = SegmentTree(s);
//    for (int i = 1; i <= m; i++) {
//        int l, r;
//        char x, y;
//        cin >> l >> r >> x >> y;
//        tree.update(l, r, x, y, 1, n, 1);
//    }
//    string res;
//    tree.query(1, n, 1, n, n, res);
//    cout << res << "\n";
//}
//
//int main() {
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    solve();
//    return 0;
//}
//

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, K = 26;
int lzy[N * 2][K], ls[N * 2], rs[N * 2], val[N * 2], idx, n, m;
char a[N];

inline int build(int l, int r) {
    int p = ++idx;
    for (int i = 0; i < K; i++)
        lzy[p][i] = i;
    if (l == r) {
        val[p] = a[l] - 'a';
        return p;
    }
    int mid = (l + r) >> 1;
    ls[p] = build(l, mid);
    rs[p] = build(mid + 1, r);
    return p;
}

inline void pushdown(int p) {
    for (int i = 0; i < K; i++)
        lzy[ls[p]][i] = lzy[p][lzy[ls[p]][i]];
    for (int i = 0; i < K; i++)
        lzy[rs[p]][i] = lzy[p][lzy[rs[p]][i]];
    for (int i = 0; i < K; i++)
        lzy[p][i] = i;
}

inline void modify(int p, int l, int r, int L, int R, int x, int y) {
    if (L <= l && r <= R) {
        for (int i = 0; i < K; i++)
            if (lzy[p][i] == x)
                lzy[p][i] = y;
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (L <= mid)
        modify(ls[p], l, mid, L, R, x, y);
    if (R > mid)
        modify(rs[p], mid + 1, r, L, R, x, y);
}

inline void print(int p, int l, int r) {
    if (l == r) {
        printf("%c", lzy[p][val[p]] + 'a');
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    print(ls[p], l, mid), print(rs[p], mid + 1, r);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> a + 1;
    n = strlen(a + 1);
    build(1, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        char x, y;
        cin >> l >> r >> x >> y;
        x = x - 'a', y = y - 'a';
        modify(1, 1, n, l, r, x, y);
    }
    print(1, 1, n);
    return 0;
}