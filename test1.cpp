#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> recoverArray(vector<int> &nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        //枚举k
        int maxK = (nums[n - 1] - nums[0]) / 2 + 1;
        set<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.insert(nums[i]);
        }
        int k = maxK;
        for (; k >= 0; k--) {
            set<int> vis;
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (vis.find(nums[i]) == vis.end()) {
                    if (arr.find(nums[i] - 2 * k) == arr.end() && arr.find(nums[i] + 2 * k) == arr.end()) {
                        flag = false;
                        break;
                    } else {
                        if (arr.find(nums[i] - 2 * k) != arr.end()) {
                            vis.insert(nums[i] - 2 * k);
                        }
                        if (arr.find(nums[i] + 2 * k) != arr.end()) {
                            vis.insert(nums[i] + 2 * k);
                        }
                    }
                }
            }
            if (flag) {
                break;
            }
        }


    }
};

int main() {


    return 0;
}