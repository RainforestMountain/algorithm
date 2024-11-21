
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //快速幂
    double myPow(double x, int n) {
        double res = 1;
        bool flag = true;
        if (n < 0) {
            flag = false;
            n = -n;
        }
        while (n != 0) {
            if ((n & 1) == 1) {
                res *= x;
            }
            x = x * x;
            n = n >> 1;
        }

        return flag ? res : 1.0 / res;
    }
};


int main() {
    Solution solution;
    cout << solution.myPow(2, -2);

    return 0;
}