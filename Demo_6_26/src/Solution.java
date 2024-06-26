import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] weight = {20, 25, 15, 25};
        int[] profit = {40, 49, 25, 60};
        int c = 62;
        List<Integer> result = solution.zeroOnebag(weight, profit, c);
        for (int i = 0; i < result.size(); i++) {
            if (i == result.size() - 1) {
                System.out.println("\n" + result.get(i) + "\n");
            } else {
                System.out.print(result.get(i) + " ");
            }
        }
    }

    public List<Integer> zeroOnebag(int[] weight, int[] profit, int c) {
        dfs(weight, profit, c, 0, c, 0);
        result.add(maxValue);
        return result;
    }

    public List<Integer> result = new ArrayList<>();
    public List<Integer> path = new ArrayList<>();
    public int maxValue = 0;

    /**
     *
     * @param weight
     * @param profit
     * @param c
     * @param i 第几个物品会被选择
     * @param rest 背包剩余容量
     * @param value 背包装入物品价值
     */
    public void dfs(int[] weight, int[] profit, int c, int i, int rest, int value) {
        int n = weight.length;
        if (i >= n) {
            if (value > maxValue) {
                result = new ArrayList<>(path);
                maxValue = value;
            }
            return;
        }
        if (rest <= 0) {
            return;
        }
        //不选择第i个物品
        dfs(weight, profit, c, i + 1, rest, value);
        //选择
        if (rest >= weight[i]) {
            path.add(i);
            dfs(weight, profit, c, i + 1, rest - weight[i], value + profit[i]);
            path.remove(path.size() - 1);
        }
    }
}
