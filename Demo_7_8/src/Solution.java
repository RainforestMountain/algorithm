public class Solution {
    public static void main(String[] args) {
        double[][] g = {
                {0, 1.2, 1.5, 1.85, 2.4, 2.8, 3.3},
                {0, 1.8, 2.0, 1.25, 2.4, 2.5, 2.6},
                {0, 1.3, 1.9, 2.2, 2.45, 2.7, 3.0}
        };
        int a = 6;

        double[][] dp = new double[4][a + 1];

        for (int i = 1; i < dp.length; i++) {
            for (int j = 1; j <= a; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i][j] = Math.max(g[i - 1][k] + dp[i - 1][j - k], dp[i][j]);
                }
            }
        }
        System.out.println(dp[3][a]);
    }
}
