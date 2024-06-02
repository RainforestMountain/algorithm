package test1;

public class Main {
    //状态压缩
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) {
            return true;
        }
        //总和小于desiredTotal,那么都输
        int sum = 0;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            sum += maxChoosableInteger;
        }
        if (sum < desiredTotal) {
            return false;
        }
        int[] dp = new int[(1 << (maxChoosableInteger + 1))];//dp[status] 为0没有计算;为1计算了,true;为-1计算了,false
        //状态1表示选择了,0表示没有选择
        return stateCompress(maxChoosableInteger, 1, desiredTotal, dp);
    }

    public static boolean stateCompress(int n, int status, int rest, int[] dp) {
        if (rest <= 0) {
            return false;
        }
        if (dp[status] != 0) {
            return dp[status] == 1;
        }
        boolean ans = false;
        for (int i = 1; i <= n; i++) {
            if (((status >> i) & 1) == 0 && !stateCompress(n, (status | (1 << i)), rest - i, dp)) {
                //如果对手没有赢,那么本次函数的先手玩家胜利,那么直接跳出往下的递归
                ans = true;
                break;
            }
        }
        dp[status] = (ans ? 1 : -1);
        return ans;
    }

    public static void main(String[] args) {
        Main m = new Main();
        System.out.println(m.canIWin(10, 1));
    }

}
