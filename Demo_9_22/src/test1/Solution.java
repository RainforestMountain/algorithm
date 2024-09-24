package test1;

import java.util.Arrays;

public class Solution {
    public int purchasePlans(int[] nums, int target) {
        int n = nums.length;
        Arrays.sort(nums);
        int left = 0;
        int right = n - 1;
        // 1   2  2   8   9
        //如果nums[left] + nums[right] > target, right--
        //                            <=  计算, 即right - left, left++, 直到 left > right
        int ans = 0;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                ans += right - left;
                left++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.purchasePlans(new int[]{1, 2, 2, 9}, 10));
    }
}
