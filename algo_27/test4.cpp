#include <iostream>
#include <bits/stdc++.h>


using namespace std;
using ll = long long;

/**
 * 228. 汇总区间
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int n = nums.size();
        int p = nums[0];
//        if (nums[0] != nums[1] - 1) {
//            res.push_back(to_string(nums[0]));
//            p = nums[1];
//        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1] - 1) {
                if (p == nums[i]) {
                    res.push_back(to_string(nums[i]));
                } else {
                    res.push_back(to_string(p) + "->" + to_string(nums[i]));
                }
                p = nums[i + 1];
            }
        }
        if (p == nums[n - 1]) {
            res.push_back(to_string(nums[n - 1]));
        } else {
            res.push_back(to_string(p) + "->" + to_string(nums[n - 1]));
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> array = {0};
    auto res = solution.summaryRanges(array);
    for (const auto &interval: res) {
        cout << interval << " ";
    }
    cout << "\n";

    return 0;
}
