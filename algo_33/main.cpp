#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int findPeakElement(vector<int> &nums) {
        // write code here
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        if (nums[0] < nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        int l = 1;
        int r = n - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1]) {
                return m;
            } else if (nums[m - 1] < nums[m] && nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
//        l = 1;
//        r = n - 2;
//        while (l <= r) {
//            int m = l + (r - l) / 2;
//            if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1]) {
//                return m;
//            } else if (nums[m - 1] < nums[m] && nums[m] < nums[m + 1]) {
//                l = m - 1;
//            } else {
//                r = m + 1;
//            }
//        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 4, 5, 2};
    cout << solution.findPeakElement(nums) << "\n";
    return 0;
}
