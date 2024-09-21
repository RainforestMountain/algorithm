import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static Read scanner = new Read();
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static void main(String[] args) throws IOException {
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] points = new int[n];
        int max = 0;
        for (int i = 0; i < points.length; i++) {
            points[i] = scanner.nextInt();
            max = Math.max(max, points[i]);
        }
        //二分
        int l = 1;
        int r = max;
        while (l <= r) {
            int d = (l + r) / 2;
            if (compute(d, points, k)) {//>= k,这个d可以,然后继续增大k
                l = d + 1;
            } else {
                r = d - 1;
            }
        }
        out.println(r);
        out.close();

    }

    public static boolean compute(int d, int[] points, int k) {
        //d过大安装不了k个灯
        int count = 1;
        int p = 0;
        for (int i = 1; i < points.length; i++) {
            if (points[i] - points[p] >= d) {
                count++;
                p = i;
            }
        }
        return count >= k;
    }
}


class Read {
    StringTokenizer st = new StringTokenizer(" ");
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(bf.readLine());
        }
        return st.nextToken();
    }

    String nextLine() throws IOException {
        return bf.readLine();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}