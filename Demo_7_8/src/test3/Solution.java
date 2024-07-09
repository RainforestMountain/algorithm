package test3;

import java.util.Random;

public class Solution {
    public static void main(String[] args) {
        int len = 10000000;
        int[] array = new int[len];
        Random random = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt() % (Integer.MAX_VALUE / 2);
        }

        long currentTime = System.currentTimeMillis();
        int[] ans = find1(array, 0, array.length - 1);
        long nextTime = System.currentTimeMillis();
        System.out.println(nextTime - currentTime);

        currentTime = System.currentTimeMillis();
        ans = find2(array, 0, array.length - 1);
        nextTime = System.currentTimeMillis();
        System.out.println(nextTime - currentTime);

    }

    public static int[] find1(int[] array, int left, int right) {
        if (right - left <= 1) {
            return new int[]{Math.min(array[left], array[right]), Math.max(array[left], array[right])};
        }

        int[] ans = new int[2];
        int mid = (left + right) / 2;
        int[] leftAns = find1(array, left, mid);
        int[] rightAns = find1(array, mid + 1, right);

        ans[0] = Math.min(leftAns[0], rightAns[0]);
        ans[1] = Math.max(leftAns[1], rightAns[1]);
        return ans;
    }

    public static int[] find2(int[] array, int left, int right) {
        int max = 0;
        int min = Integer.MAX_VALUE;

        for (int i = left; i <= right; i++) {
            max = Math.max(array[i], max);
            min = Math.min(array[i], min);
        }
        return new int[]{max, min};
    }
}
