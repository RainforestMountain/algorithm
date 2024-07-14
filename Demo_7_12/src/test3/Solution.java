package test3;

import java.util.Arrays;

public class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[] dp = new int[amount + 1];
        int[] diagnosis = new int[amount + 1];
        Arrays.sort(coins);
        dp[0] = 0;
        for (int i = 0; i < coins.length; i++) {
            for (int j = 1; j < dp.length; j++) {
                if (j >= coins[i]) {
                    if (j == coins[i] || dp[j - coins[i]] > 0) { //dp[j] j > 0时必须要凑得齐才能算在内,即dp[j] > 0,
                        // 否则最后就是凑不齐的硬币数
                        dp[j] = (dp[j] == 0 ? dp[j - coins[i]] + 1 : Math.min(dp[j], dp[j - coins[i]] + 1));
                    }
                }
            }
        }
        diagnosis[0] = 0;
        for (int i = 0; i < coins.length; i++) {
            for (int j = 1; j < dp.length; j++) {
                if (j >= coins[i]) {
                    diagnosis[j] = Math.max(diagnosis[j], diagnosis[j - coins[i]] + coins[i]);
                }
            }
        }

        return diagnosis[amount] == amount ? dp[amount] : -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int change = solution.coinChange(new int[]{186, 419, 83, 408}, 6249);
        System.out.println(change);
    }
}
