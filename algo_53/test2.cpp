#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
public:
    explicit SegmentTree(int n) {
        tree = vector<int>(4 * n);
        lazy = vector<int>(4 * n);
        buildTree(1, 1, n);
    }

    void push_up(int rt) {
        tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
    }

    void push_down(int rt) {
        lazy[rt << 1] = lazy[rt];
        lazy[rt << 1 | 1] = lazy[rt];
        tree[rt << 1] = max(tree[rt << 1], lazy[rt << 1]);
        tree[rt << 1 | 1] = max(tree[rt << 1 | 1], lazy[rt << 1 | 1]);
    }

    void buildTree(int rt, int l, int r) {
        if (l == r) {
            tree[rt] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(rt << 1, l, mid);
        buildTree(rt << 1 | 1, mid + 1, r);
        push_up(rt);
    }

    //[a, b] 赋值成x
    void update(int a, int b, int x, int rt, int l, int r) {
        if (a <= l && r <= b) {
            tree[rt] = x;
            lazy[rt] = x;
            return;
        }
        push_down(rt);
        int mid = (l + r) >> 1;
        if (a <= mid) {
            update(a, b, x, rt << 1, l, mid);
        }
        if (b > mid) {
            update(a, b, x, rt << 1 | 1, mid + 1, r);
        }
        push_up(rt);
    }

    int query(int a, int b, int rt, int l, int r) {
        if (a <= l && r <= b) {
            return tree[rt];
        }
        push_down(rt);
        int mid = (l + r) >> 1;
        int res = 0;
        if (a <= mid) {
            res = max(res, query(a, b, rt << 1, l, mid);)
        }
        if (b > mid) {
            res = max(res, query(a, b, rt << 1 | 1, mid + 1, r));
        }
        return res;
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        std::sort(positions.begin(), positions.end(), [](auto o1, auto o2) {
            return (o1[0] == o2[0] ? o1[1] < o2[0] : o1[0] < o2[0]);
        });
        //离散化
        map<int, int> origin;
        for (int i = 0; i < positions.size(); i++) {
            origin[positions[i][0] + positions[i]] = i + 1;
        }
        int n = origin.size();
        SegmentTree tree = SegmentTree(n);
        int res = 0;
        map<int, int> right;
        for (int i = 0; i < positions.size(); i++) {
            //二分查找试试
            // [1, 3] [2, 5] , [6, 7]
            //
        }


    }
};

int main() {

    return 0;
}