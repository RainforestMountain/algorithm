package test1;

import java.util.List;

class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {
    }

    Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
    }

    public Node(boolean _val, boolean _isLeaf, Node _topLeft, Node _topRight, Node _bottomLeft, Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

public class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        if (quadTree1 == null) {
            return quadTree2;
        } else if (quadTree2 == null) {
            return quadTree1;
        }
        return dfs(quadTree1, quadTree1.val, quadTree2, quadTree2.val);
    }

    public Node dfs(Node quadTree1, boolean val1, Node quadTree2, boolean val2) {
        Node res = new Node();
        if (quadTree1 == null && quadTree2 != null) {
            if (val1) {//值为1
                res = null;
            } else {
                res = quadTree2;
            }
            return res;
        } else if (quadTree1 != null && quadTree2 == null) {
            if (val2) {
                res = null;
            } else {
                res = quadTree1;
            }
            return res;
        } else if (quadTree1 == null && quadTree2 == null) {
            return null;
        }
        //四个节点
        res.val = quadTree1.val || quadTree2.val;
        if (quadTree1.topLeft == null && quadTree1.val == true || quadTree2.topLeft == null && quadTree2.val == true) {
            res.isLeaf = true;
        }
        res.topLeft = dfs(quadTree1.topLeft, quadTree1.val, quadTree2.topLeft, quadTree2.val);
        res.topRight = dfs(quadTree1.topRight, quadTree1.val, quadTree2.topRight, quadTree2.val);
        res.bottomLeft = dfs(quadTree1.bottomLeft, quadTree1.val, quadTree2.bottomLeft, quadTree2.val);
        res.bottomRight = dfs(quadTree1.bottomRight, quadTree1.val, quadTree2.bottomRight, quadTree2.val);
        return res;
    }

    public boolean isAcronym(List<String> words, String s) {
        StringBuilder str = new StringBuilder();
        for (String word : words) {
            str.append(word.charAt(0));
        }

        if (str.toString().equals(s)) {
            return true;
        } else {
            return false;
        }
    }

    public static void main1(String[] args) {
        Solution solution = new Solution();
        Node quadTree1 = new Node(true, false);
        quadTree1.topLeft = new Node(true, true);
        quadTree1.topRight = new Node(true, true);
        quadTree1.bottomLeft = new Node(true, true);
        quadTree1.bottomRight = new Node(false, true);

        Node quadTree2 = new Node(true, false);
        quadTree2.topLeft = new Node(true, true);
        quadTree2.topRight = new Node(true, false);
        quadTree2.topRight.topLeft = new Node(false, true);
        quadTree2.topRight.topRight = new Node(false, true);
        quadTree2.topRight.bottomLeft = new Node(true, true);
        quadTree2.topRight.bottomRight = new Node(true, true);
        quadTree2.bottomLeft = new Node(true, true);
        quadTree2.bottomRight = new Node(false, true);
        Node node = solution.intersect(quadTree1, quadTree2);

        System.out.println();
    }

    public boolean canMakeSubsequence(String str1, String str2) {
        int i = 0;
        int j = 0;

        while (i < str1.length() && j < str2.length()) {
            if ((str1.charAt(i) - 'a' + 1) % 26 == (str2.charAt(j) - 'a') || str1.charAt(i) == str2.charAt(j)) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (j == str2.length()) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.canMakeSubsequence("abc", "ad"));
    }

    public int minimumIndex(List<Integer> nums) {
        List<Integer> right = 
    }
}
