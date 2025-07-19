import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int fresh = 0;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new int[]{i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        //统计最大步长
        int res = 0;
        //不过最后结果fresh为0,才是有效
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        int step = 0;
        while (!queue.isEmpty()) {
            //整体扩散， bfs
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.poll();
                for (int t = 0; t < 4; t++) {
                    int nx = cur[0] + dx[t];
                    int ny = cur[1] + dy[t];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        queue.add(new int[]{nx, ny});
                        grid[nx][ny] = 2;
                        fresh--;
                    }
                }
            }
            step++;
        }
        res = Math.max(res, step - 1);
        if (fresh > 0) {
            res = -1;
        }
        return res;
    }
}