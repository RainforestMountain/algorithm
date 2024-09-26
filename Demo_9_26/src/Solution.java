import java.util.Arrays;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Solution {
    public double minimalExecTime(TreeNode root) {
        return dfs(root)[1];
    }

    /**
     * @param root
     * @return 返回数组, 第一个元素执行的总时间, 第二个元素并行化处理后最少的执行时间
     */
    public double[] dfs(TreeNode root) {
        if (root == null) {
            return new double[]{0, 0};
        }
        double[] left = dfs(root.left);
        double[] right = dfs(root.right);
        return new double[]{left[0] + right[0] + root.val,
                Math.max((left[0] + right[0]) / 2, Math.max(left[1], right[1])) + root.val};
    }

    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if ((sum + target) % 2 != 0) {
            return 0;
        }
        int x = (sum + target) / 2;
        int[] dp = new int[x + 1];

        dp[0] = 1;
        for (int j = 1; j <= x; j++) {
            for (int i = 0; i < nums.length; i++) {
                if (j >= nums[i]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        System.out.println(Arrays.toString(dp));
        return dp[x];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.findTargetSumWays(new int[]{1, 1, 1, 1, 1}, 3));
    }
}
