#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//using ll = long long;
#define ll long long
class Solution {
public:
    /**
     * 判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
     * @param n
     * @return
     */
    bool isPowerOfTwo(int n) {
        return lowbit(n) == n && n != 0;
    }

    int lowbit(ll  n) {
        return n & (-n);
    }
};

int main() {
    Solution solution;
    cout << solution.isPowerOfTwo(20) << "\n";
    return 0;
}
