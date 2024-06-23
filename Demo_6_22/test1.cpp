#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 函数用于获取数组的最大极差
int maxDifference(vector<int>& nums) {
    // 对数组进行排序
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // 初始化极差为数组中最大值和最小值之差
    int maxVal = nums[n - 1], minVal = nums[0], diff = maxVal - minVal;

    // 标记数组中每个元素是否已经被作为 a_i 加过
    vector<bool> added(n, false);

    // 从数组的最小值开始，尝试与后面的元素相加
    for (int i = 0; i < n - 1; ++i) {
        if (!added[i]) {
            // 如果当前元素是负数，尝试与后面的正数相加
            for (int j = i + 1; j < n; ++j) {
                if (!added[j]) {
                    nums[i] += nums[j];
                    added[j] = true; // 标记 j 已经被加过
                    maxVal = max(maxVal, nums[i]);
                    minVal = min(minVal, nums[i]);
                    diff = max(diff, maxVal - minVal);
                    // 由于每个元素至多只能被选作 a_i 一次，所以 j 不能再被选作 a_i
                    break;
                }
            }
        }
    }

    return diff;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << maxDifference(nums) << endl;
    }
    return 0;
}