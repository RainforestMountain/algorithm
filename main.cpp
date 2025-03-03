#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        set<TreeNode *> p_nodes;
        set<TreeNode *> q_nodes;
        getPath(root, p, p_nodes);
        getPath(root, q, q_nodes);
        for (auto it = q_nodes.end(); it != q_nodes.begin(); it--) {
            if (p_nodes.find(*it) != p_nodes.end()) {
                return *it;
            }
        }
        if (p_nodes.find(*q_nodes.begin()) != p_nodes.end()) {
            return *q_nodes.begin();
        }
        return nullptr;
    };

    bool getPath(TreeNode *root, TreeNode *&p, set<TreeNode *> &nodes) {
        if (root == nullptr) {
            return false;
        }
        if (root == p) {
            nodes.insert(root);
            return true;
        }
        bool ans = getPath(root->left, p, nodes);
        ans = ans | getPath(root->right, p, nodes);
        if (ans) {
            nodes.insert(root);
        }
        return ans;
    }
};

int main() {

    return 0;
}
