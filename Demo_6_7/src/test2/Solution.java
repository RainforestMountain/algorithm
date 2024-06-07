package test2;

import java.util.Arrays;

public class Solution {
    //暴力递归,优化为记忆化搜索
    public int numDecodings1(String s) {
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        int ans = func(new StringBuilder(s), 0, dp);
        System.out.println(Arrays.toString(dp));
        return ans;
    }

    public int func(StringBuilder s, int index, int[] dp) {
        if (index >= s.length()) {//到最后了,不分割了,只有一种编码了
            return 1;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        //选择一个字符
        int code = Integer.parseInt(s.substring(index, index + 1));
        int ans = 0;
        //方法数,不是步数,不是遍历经过的字符情况,所以要先分步乘法再分类加法
        if (code >= 1 && code <= 9) {
            //可以解码
            ans += 1 * func(s, index + 1, dp);
        }
        //选择两个字符
        if (index + 2 <= s.length()) {
            code = Integer.parseInt(s.substring(index, index + 2));
            if (code >= 10 && code <= 26) {
                ans += 1 * func(s, index + 2, dp);
            }
        }
        dp[index] = ans;
        return ans;
    }

    public int numDecodings(String s) {
        int n = s.length();
        StringBuilder temp = new StringBuilder(s);
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            int ans = 0;
            int code = Integer.parseInt(temp.substring(i, i + 1));
            if (code >= 1 && code <= 9) {
                ans += dp[i + 1];
            }
            if (i + 2 <= n) {
                code = Integer.parseInt(temp.substring(i, i + 2));
                if (code >= 10 && code <= 26) {
                    ans += dp[i + 2];
                }
            }
            dp[i] = ans;
        }
        System.out.println(Arrays.toString(dp));
        return dp[0];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.numDecodings("06"));
    }
}
