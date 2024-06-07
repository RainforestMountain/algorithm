package test1;

import java.util.Arrays;

public class Solution {
    //暴力递归,优化为记忆化搜索
    public int mincostTickets1(int[] days, int[] costs) {
        int n = days.length;
        int[] dp = new int[n];
        //Arrays.fill(dp, Integer.MAX_VALUE);
        int[] during = {1, 7, 30};
        int ans = func(days, 0, costs, during, dp);
        System.out.println(Arrays.toString(dp));
        return ans;
    }

    //func(..,i...)days中第i个下标开始旅游的最低花费
    public int func(int[] days, int i, int[] costs, int[] during, int[] dp) {
        if (i == days.length) {
            return 0;
        }
        if (dp[i] != 0) {
            return dp[i];
        }
        int ans = Integer.MAX_VALUE;//ans要得到最小值
        for (int k = 0; k < 3; k++) {
            //找到持续时间最长的下标的下一个位置,即又要购买票的位置
            int j = i;
            //持续时间是end - start + 1
            while (j < days.length && days[i] + during[k] > days[j]) {
                j++;
            }
            ans = Math.min(ans, costs[k] + func(days, j, costs, during, dp));
        }
        dp[i] = ans;
        return ans;
    }

    //非递归的
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        int[] dp = new int[n + 1];
        int[] during = {1, 7, 30};
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            for (int k = 0; k < 3; k++) {
                while (j < days.length && days[i] + during[k] > days[j]) {
                    j++;
                }
                dp[i] = Math.min(dp[i], costs[k] + dp[j]);
            }
        }
        return dp[0];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.mincostTickets(new int[]{1, 4, 6, 7, 8, 20}, new int[]{2, 7, 15}));
    }
}