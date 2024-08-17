import java.util.Arrays;

public class Solution {
    public int numSquares(int n) {
        //dp[i] 和为i的完全平方数的最少数量
        //拆分 i 可以拆分为 x 和 i - x, x 是完全平方数, 然后取最小

        int[] dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1;
        for (int j = 1; j * j <= n; j++) {
            dp[j * j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (dp[i] == 0) {
                    dp[i] = dp[j * j] + dp[i - j * j];
                } else {
                    dp[i] = Math.min(dp[j * j] + dp[i - j * j], dp[i]);
                }
            }
        }
        return dp[n];
   }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.numSquares(12));
    }

   
}
