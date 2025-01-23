#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//力扣 228.汇总区间
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = 0;
        vector<string> res;
        for (; r < n;) {
            if (r < n - 1 && nums[r] == nums[r + 1] - 1) {
                r++;
            } else {
                if (r - l + 1 > 1) {
                    string path = to_string(nums[l]) + "->" + to_string(nums[r]);
                    res.push_back(path);
                } else {
                    res.push_back(to_string(nums[r]));
                }
                r++;
                l = r;
            }
        }
        return res;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {0, 2, 3, 6, 8, 9};
    auto res = solution.summaryRanges(nums);
    for (const auto &item: res) {
        cout << item << " ";
    }
    cout << "\n";
    return 0;
}