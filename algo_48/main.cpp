#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 10e5 + 2;
int sequence[N];
int len1[N << 2], pre1[N << 2], suf1[N << 2], len0[N << 2], pre0[N << 2], suf0[N << 2], sum[N << 2];
int change[N << 2], rever[N << 2];
int n = 1;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void push_up(int rt) {
    int lchild = rt << 1, rchild = rt << 1 | 1;
    //len看是否左右区间是否有一个完全贯穿连续 ,会影响前后缀的写法
    pre1[rt] = (len1[lchild] == pre1[lchild] && len1[lchild] != 0 ? pre1[lchild] + pre1[rchild] : pre1[lchild]);
    suf1[rt] = (len1[rchild] == pre1[rchild] && len1[rchild] != 0 ? suf1[lchild] + suf1[rchild] : suf1[rchild]);
    len1[rt] = max(len1[lchild], max(len1[rchild], suf1[lchild] + pre1[rchild]));
    pre0[rt] = (len0[lchild] == pre0[lchild] && len0[lchild] != 0 ? pre0[lchild] + pre0[rchild] : pre0[lchild]);
    suf0[rt] = (len0[rchild] == pre0[rchild] && len0[rchild] != 0 ? suf0[lchild] + suf0[rchild] : suf0[rchild]);
    len0[rt] = max(len0[lchild], max(len0[rchild], suf0[lchild] + pre0[rchild]));
    sum[rt] = sum[lchild] + sum[rchild];
}

//反转操作会被更新覆盖操作所无效
void changeLazy(int rt, int l, int r, int x) {
    int tp = r - l + 1;
    change[rt] = x;
    rever[rt] = false;
    if (change[rt] == 1) {
        pre1[rt] = tp, suf1[rt] = tp, len1[rt] = tp;
        pre0[rt] = 0, suf0[rt] = 0, len0[rt] = 0;
        sum[rt] = tp;
    } else {
        pre1[rt] = 0, suf1[rt] = 0, len1[rt] = 0;
        pre0[rt] = tp, suf0[rt] = tp, len0[rt] = tp;
        sum[rt] = 0;
    }
}

//111100010000011 pre1 = 4, pre0 = 0, len1 = 4, len0 = 5 , suf1 = 2, suf0 = 0, sum = 7
//000011101111100 pre1 = 0, pre0 = 4, len1 = 5, len0 = 4,  suf1 = 0, suf0 = 2, sum = 15 - 7 = 8
void reverseLazy(int rt, int l, int r) {
    rever[rt] = !rever[rt];
    swap(pre1[rt], pre0[rt]), swap(suf1[rt], suf0[rt]), swap(len1[rt], len0[rt]);
    sum[rt] = (r - l + 1) - sum[rt];
}


void push_down(int rt, int l, int r) {
    int lchild = rt << 1, rchild = rt << 1 | 1;
    int mid = (l + r) >> 1;
    if (change[rt] != 0) {
        changeLazy(lchild, l, mid, change[rt]);
        changeLazy(rchild, mid + 1, r, change[rt]);
        change[rt] = 0;
    }
    if (rever[rt] != 0) {
        reverseLazy(lchild, l, mid);
        reverseLazy(rchild, mid + 1, r);
        rever[rt] = 0;
    }
}

void buildTree(int rt = 1, int l = 1, int r = n) {
    len1[rt] = 0, pre1[rt] = 0, suf1[rt] = 0;
    len0[rt] = 0, pre0[rt] = 0, suf0[rt] = 0;
    sum[rt] = 0;
    if (l == r) {
        if (sequence[l] == 1) {
            len1[rt] = 1, pre1[rt] = 1, suf1[rt] = 1;
            len0[rt] = 0, pre0[rt] = 0, suf0[rt] = 0;
            sum[rt] = 1;
        } else {
            len1[rt] = 0, pre1[rt] = 0, suf1[rt] = 0;
            len0[rt] = 1, pre0[rt] = 1, suf0[rt] = 1;
            sum[rt] = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(rt << 1, l, mid);
    buildTree(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}


//更新覆盖 x = -1,覆盖为0 ;x = 1, 覆盖为1
void update(int a, int b, int x, int rt = 1, int l = 1, int r = n) {
    int tp = r - l + 1;
    if (a <= l && r <= b) {
        changeLazy(rt, l, r, x);
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r);
    if (a <= mid) {
        update(a, b, x, rt << 1, l, mid);
    }
    if (b > mid) {
        update(a, b, x, rt << 1 | 1, mid + 1, r);
    }
    push_up(rt);
}

void reverse(int a, int b, int rt = 1, int l = 1, int r = n) {
    if (a <= l && r <= b) {
        reverseLazy(rt, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r);
    if (a <= mid) {
        reverse(a, b, rt << 1, l, mid);
    }
    if (b > mid) {
        reverse(a, b, rt << 1 | 1, mid + 1, r);
    }
    push_up(rt);
}

int querySum(int a, int b, int rt = 1, int l = 1, int r = n) {
    if (a <= l && r <= b) {
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r);
    int ans = 0;
    if (a <= mid) {
        ans += querySum(a, b, rt << 1, l, mid);
    }
    if (b > mid) {
        ans += querySum(a, b, rt << 1 | 1, mid + 1, r);
    }
    return ans;
}

//第一个元素指与被  任务影响到的区间  最长连续的1, 第二个是连续最长前缀, 第三个是连续最长后缀
vector<int> queryLongest(int a, int b, int rt = 1, int l = 1, int r = n) {
    if (a <= l && r <= b) {
        return {len1[rt], pre1[rt], suf1[rt]};
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r);
    vector<int> larr;
    vector<int> rarr;
    if (a <= mid) {
        larr = queryLongest(a, b, rt << 1, l, mid);
    }
    if (b > mid) {
        rarr = queryLongest(a, b, rt << 1 | 1, mid + 1, r);
    }
    //larr, rarr 不可能全部为空
    if (larr.empty()) {
        return rarr;
    }
    if (rarr.empty()) {
        return larr;
    }
    vector<int> res(3);
    res[0] = max(larr[0], max(rarr[0], larr[2] + rarr[1]));
    //接下来看是否完全贯穿, 左侧被任务影响到区间的左边界是max(a, l)
    res[1] = (larr[0] >= mid - max(a, l) + 1 && larr[0] != 0 ? larr[1] + rarr[1] : larr[1]);
    res[2] = (rarr[0] >= min(b, r) - (mid + 1) + 1 && rarr[0] != 0 ? larr[2] + rarr[2] : rarr[2]);
    return res;
}

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> sequence[i];
    }
    buildTree();
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        l++, r++;
        if (op == 0) {
            update(l, r, 0);
        } else if (op == 1) {
            update(l, r, 1);
        } else if (op == 2) {
            reverse(l, r);
        } else if (op == 3) {
            int res = querySum(l, r);
            cout << res << "\n";
        } else if (op == 4) {
            auto res = queryLongest(l, r);
            cout << res[0] << "\n";
        }
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
