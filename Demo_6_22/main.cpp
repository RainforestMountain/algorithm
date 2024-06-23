#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        //很难想一个dp的递推公式,直接用多个dp表示不同的状态
        vector<ll> fmax(n);//fmax[i]以i结尾的最大子数组的乘积
        vector<ll> fmin(n);//fmin[i] 以i结尾的最小子数组的乘积
        fmax[0] = nums[0];
        fmin[0] = nums[0];
        ll ma = INT_MIN;
        for (int i = 1; i < n; i++) {
            fmax[i] = max(fmax[i - 1] * (ll)nums[i], max(fmin[i - 1] *(ll) nums[i], (ll)nums[i]));
            fmin[i] = min(fmax[i - 1] * (ll)nums[i], min(fmin[i - 1] *(ll) nums[i], (ll)nums[i]));
            ma = max(ma, fmax[i]);
        }
        for (int i = 0; i < n; i++) {
            cout << fmax[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << fmin[i] << " ";
        }
        cout << "\n";
        return (int)ma;

    }
};

int main() {
    Solution solution;
    vector<int> nums({0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0});
    cout << solution.maxProduct(nums);
}