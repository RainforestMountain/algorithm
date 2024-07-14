package test2;

import java.util.Arrays;

public class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] array = new int[n + 2];
        array[0] = 1;
        array[array.length - 1] = 1;
        System.arraycopy(nums, 0, array, 1, array.length - 1 - 1);
        int[][] dp = new int[n + 2][n + 2];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(array, 0, array.length - 1, dp);
    }

    public int solve(int[] array, int left, int right, int[][] dp) {
        if (left >= right - 1) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int ans = 0;
        for (int i = left + 1; i < right; i++) {
            ans = Math.max(ans, array[left] * array[i] * array[right] + solve(array, left, i, dp) + solve(array, i, right, dp));
        }

        dp[left][right] = ans;
        return dp[left][right];
    }
}
