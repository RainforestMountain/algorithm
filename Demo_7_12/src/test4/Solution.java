package test4;

public class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        //从起始到终点要考虑两个参数,会同时影响决策,不满足后无效性
        //从终点到起始点,就只用考虑初始值了,不用考虑剩余健康值的增加

        int m = dungeon.length;
        int n = dungeon[0].length;

        int[][] dp = new int[m + 1][n + 1];//dp[i][j] (i,j)到终点的最小初始健康值

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = Math.max(Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.calculateMinimumHP(new int[][]{
                {-2, -3, 3},
                {-5, -10, 1},
                {10, 30, -5}
        }));
    }
}
