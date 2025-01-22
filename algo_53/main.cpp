
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
//权值线段树
//遇到这个数之前有多少数是满足nums[i] > 2 * nums[j]

class SegmentTree {
private:
    vector<ll> tree;
    vector<ll> lazy;

public:
    SegmentTree(int n) {
        tree = vector<ll>(4 * n);
        lazy = vector<ll>(4 * n);
    }

    void push_up(int rt) {
        tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
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

    void update(int a, int b, int x, int rt, int l, int r) {
        if (a <= l && r <= b) {
            tree[rt] += (r - l + 1) * x;
            return;
        }
        //push_down();
        int mid = (l + r) >> 1;
        if (a <= mid) {
            update(a, b, x, rt << 1, l, mid);
        }
        if (b > mid) {
            update(a, b, x, rt << 1 | 1, mid + 1, r);
        }
        push_up(rt);
    }

    ll query(int a, int b, int rt, int l, int r) {
        if (a <= l && r <= b) {
            return tree[rt];
        }
        //push_down
        int mid = (l + r) >> 1;
        ll res = 0;
        if (a <= mid) {
            res += query(a, b, rt << 1, l, mid);
        }
        if (b > mid) {
            res += query(a, b, rt << 1 | 1, mid + 1, r);
        }
        return res;
    }

};
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        vector<ll> array(n);
        for (int i = 0; i < n; i++) {
            array[i] = nums[i];
        }
        vector<ll> tp = vector<ll>(array);
        std::sort(array.begin(), array.end());
        auto last = unique(array.begin(), array.end());
        array.erase(last, array.end());
        map<ll, ll> ls;
        map<ll, ll> origin;
        for (int i = 0; i < array.size(); i++) {
            ls[i + 1] = array[i];
            origin[array[i]] = i + 1;
        }
        int res = 0;
        SegmentTree tree = SegmentTree(n);
        for (int i = 0; i < n; i++) {
            int index = (int) origin[tp[i]];
            ll d = 2 * tp[i];
            auto it = origin.upper_bound(d);
            if (it != origin.end()) {
                int t = (int) (*it).second;
                res += (int) tree.query(t, n, 1, 1, n);
            }
            tree.update(index, index, 1, 1, 1, n);
        }
        return res;

    }
};


int main() {
    Solution solution;
    vector<int> nums = {2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647};
    cout << solution.reversePairs(nums) << "\n";
    return 0;
}
