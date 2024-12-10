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
    int minNumberInRotateArray(vector<int> &nums) {
        // write code here
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        //关键在于判断是在左侧还是在右侧区域,左侧尽量跳过,右侧保留, 而且必须能唯一确定,不能因为等号含糊不清
        //得用l,因为最后要落在右侧,会有nums[m] >= nums[l]
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) { //在左侧区域了,
                l = m + 1;
            } else if (nums[m] < nums[r]) {//一定在右侧区域
                r = m;
            } else {//
                r--;//不完全确定, 不符合前面两个完全小于大于的条件,那就缩小范围,右侧的r一定不是唯一的最小值
                //因为nums[m] = nums[r], 且m< r, r--不影响找最小值,还有一个m

            }
        }
        return nums[r];
    }
};

int main() {
    vector<int> v = {2,2,2,1,2};
    Solution solution;
    cout << solution.minNumberInRotateArray(v) << "\n";
    return 0;
}
