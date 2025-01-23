#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//力扣219. 存在重复元素2
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            //如果前面有相同的值, 那就判断下标的情况
            if (mp.find(nums[i]) != mp.end()) {
                if (abs(mp[nums[i]] - i) <= k) {
                    return true;
                }
            } else {
                //没有相同的值, 更新到最新
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {1,2,3,1};
    cout << solution.containsNearbyDuplicate(nums, 3) << "\n";
    return 0;
}
