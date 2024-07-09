package test2;

public class Main {
    public static void main(String[] args) {
        int C = 10500;
        double[][] dp = new double[4][C + 1];
        double[] r = {0.9, 0.8, 0.5};
        int[] c = {3000, 1500, 2000};
        int[] u = {2, 3, 3};

        for (int i = 1; i < dp.length; i++) {
            for (int j = 0; j <= C; j++) {
                for (int k = 1; k <= (j - (6500 - c[i - 1])) * 1.0 / c[i - 1]; k++) {
                    if (j >= k * c[i - 1]) {
                        if (dp[i][j] != 0) {
                            dp[i][j] = Math.max(((1.0 - Math.pow(1.0 - r[i - 1], k)) * dp[i - 1][j - k * c[i - 1]]),dp[i][j]);
                        } else {
                            dp[i][j] = ((1.0 - Math.pow(1.0 - r[i - 1], k)) * dp[i - 1][j - k * c[i - 1]]);
                        }

                    }
                }
            }
        }

        System.out.println(dp[3][C]);

    }
}
