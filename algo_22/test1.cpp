#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        //窗口只有两种数字
        unordered_map<int, int> m;
        int left = 0, right = 0;
        int n = fruits.size();
        int res = 0;
        for (; right < n; right++) {
            int type = fruits[right];
            if (m.size() < 2 || (m.size() == 2 && m.find(type) != m.end())) {
                m[type]++;
                continue;
            }
            m[type]++;
            res = max(right - left, res);
            while (left <= right && m.size() > 2) {
                m[fruits[left]]--;
                if (m[fruits[left]] == 0) {
                    m.erase(fruits[left]);
                }
                left++;
            }
        }
        res = max(right - left, res);
        return res;
    }

    /**
     * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
     * 子数组是数组中元素的连续非空序列。
     * @param nums
     * @param k
     * @return
     */
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        //sum[i, j] = prefix[j] - prefix[i - 1]
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (prefix[j] - prefix[i - 1] == k) {
                    res++;
                }
            }
        }
        return res;
    }

};

int main() {

    Solution solution;
    vector<int> fruits = {0, 1, 1, 4, 3};
    vector<int> nums = {-1, -1, 1};
//    cout << solution.totalFruit(fruits) << "\n";
    cout << solution.subarraySum(nums, 0) << "\n";
    return 0;
}