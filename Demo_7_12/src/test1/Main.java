package test1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        FastReader reader = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int t = reader.nextInt();
        while (t > 0) {
            int n = reader.nextInt();
            int m = reader.nextInt();
            int k = reader.nextInt();
            char[] arr = new char[n + 2];
            arr[0] = 'L';
            String s = reader.next();
            for (int i = 1; i <= n; i++) {
                arr[i] = s.charAt(i - 1);
            }
            int distance = 0;
            for (int i = 0; i <= distance && i <= n; i++) {
                if (arr[i] == 'L') {
                    distance = Math.max(distance, i + m);
                } else if (arr[i] == 'W') {
                    boolean flag = false;
                    if (distance == i) {
                        flag = true;
                    } else {
                        flag = true;
                        for (int j = i + 1; j <= distance && j <= n; j++) {
                            if (arr[j] == 'L') {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        for (int j = 0; j <= k && i + j <= n + 1; j++) {
                            if (arr[i + j] == 'C') {
                                distance = Math.max(distance, i + j - 1);
                                k -= (j - 1);
                                break;
                            }
                            if (arr[i + j] == 'L') {
                                distance = Math.max(distance, i + j);
                                k -= j;
                                break;
                            }
                            if (i + j == n + 1 && arr[i + j - 1] != 'C') {
                                distance = n + 1;
                                break;
                            }
                        }
                    }
                }
            }
            if (distance >= n + 1) {
                out.println("YES");
            } else {
                out.println("NO");
            }

            t--;
        }

        out.flush();
        out.close();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}