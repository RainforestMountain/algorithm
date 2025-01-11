#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ret {
    int l;
    int b;
    int r;
    int t;

    ret() {}

    ret(int l, int b, int r, int t) : l(l), b(b), r(r), t(t) {}

    bool operator==(const ret &rhs) const {
        return l == rhs.l && b == rhs.b && r == rhs.r && t == rhs.t;
    }

    bool operator<(const ret &rhs) const {
        return l == rhs.l ? r < rhs.r : l < rhs.l;
    }
};

struct Tree {
    vector<ll> t;
    vector<ret> ls;//离散化
    map<ret, int> index;
    int n;

    Tree(vector<ret> &retans) {
        n = retans.size() - 1;
        t = vector<ll>(n + 1);
        ls = vector<ret>(retans);
        sort(ls.begin() + 1, ls.end());
        for (int i = 1; i <= n; i++) {
            index[ls[i]] = i;
        }
    }

    void update(int i, ll x) {
        while (i <= n) {
            t[i] += x;
            i += lowbit(i);
        }
    }

    ll getArea(ret &re) {

    }

    int lowbit(int i) {
        return i & (-i);
    }
};


void solve() {
    int n;
    cin >> n;
    Tree tree;
    vector<ret> retans(n + 1);
    for (int i = 1; i <= n; i++) {
        int li, bi, ri, ti;
        cin >> li >> bi >> ri >> ti;
        retans[i] = ret(li, bi, ri, ti);
    }


}


int main() {


    return 0;
}
