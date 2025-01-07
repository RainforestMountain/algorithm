#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = nullptr;
        int n = preorder.size();
        int t = 0;
        build(root, 0, n - 1, t, preorder, inorder);
        return root;
    }

    void build(TreeNode *&root, int l, int r, int &t, vector<int> &pre, vector<int> &in) {
        if (l > r) {
            return;
        }
        int index = -1;
        //在中序序列里面即子树找根
        for (int i = l; i <= r; i++) {
            if (in[i] == pre[t]) {
                index = i;
                break;
            }
        }
        root = new TreeNode(in[index]);
        t++;//左右子树的根需要++
        build(root->left, l, index - 1, t, pre, in);
        build(root->right, index + 1, r, t, pre, in);
    }

    void postOrder(TreeNode *root, string &res) {
        if (root == nullptr) {
            return;
        }
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.insert(res.size(), to_string(root->val));
        res.push_back(' ');
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    TreeNode *root = solution.buildTree(pre, in);
    string res;
    solution.postOrder(root, res);
    res.pop_back();
    cout << res;
    return 0;
}