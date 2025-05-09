package test1;


import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}


public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        lists[0] = new ArrayList<>();
        lists[1] = new ArrayList<>();
        dfs(root, p);
        pos++;
        dfs(root, q);
        TreeNode result = null;
        for (int i = 0, j = 0; i < lists[0].size() && j < lists[1].size(); i++, j++) {
            if (lists[0].get(i) == lists[1].get(j)) {
                result = lists[0].get(i);
                break;
            }
        }
        System.out.println("p:");
        for (TreeNode node : lists[0]) {
            System.out.print(node.val + " ");
        }
        System.out.println("\nq:");
        for (TreeNode node : lists[1]) {
            System.out.print(node.val + " ");
        }
        return result;
    }

    public List<TreeNode>[] lists = new List[2];
    public int pos = 0;

    public int dfs(TreeNode root, TreeNode target) {
        if (root == target) {
            lists[pos].add(target);
            return 1;
        }
        if (root == null) {
            return 0;
        }
        int res1 = dfs(root.left, target);
        int res2 = dfs(root.right, target);

        if (res1 == 1) {
            lists[pos].add(root);
            return 1;
        } else if (res2 == 1) {
            lists[pos].add(root);
            return 1;
        } else {
            return 0;
        }
    }


}
