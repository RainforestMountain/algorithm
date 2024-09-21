package test2;

import java.io.*;
import java.util.*;

public class Main {
    static Read scanner = new Read();
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] matrix = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        boolean[][] visited = new boolean[n + 1][m + 1];
        out.println(bfs(matrix, visited));
        out.close();
    }

    //dp不行, bfs 加贪心
    public static int bfs(int[][] matrix, boolean[][] visited) {
        int n = matrix.length - 1;
        int m = matrix[0].length - 1;
        Queue<int[]> q = new LinkedList<>();//0优先去拓展
        PriorityQueue<int[]> choices = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
        q.add(new int[]{1, 1, matrix[1][1]});//(i, j, distance)
        visited[1][1] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.peek()[0];
                int y = q.peek()[1];
                int val = q.peek()[2];
                if (x == n && y == m) {

                }
                q.poll();
                visited[x][y] = true;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny]) {
                        choices.add(new int[]{nx, ny, matrix[nx][ny]})
                    }

                }
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny]) {
                        q.add(new int[]{nx, ny, matrix[nx][ny] + val});
                    }
                }
            }
        }
        return path.peek();
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
