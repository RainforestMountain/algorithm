#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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
    int countUnivalSubtrees(TreeNode *root) {
        dfs(root);
        return result;
    }

    int result = 0;

    bool dfs(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        bool ans = false;
        if (left && right) {
            if (root->left != nullptr && root->right != nullptr) {
                if (root->val == root->left->val && root->val == root->right->val) {
                    ans = true;
                    result++;
                }
            } else if (root->left != nullptr && root->right == nullptr) {
                if (root->val == root->left->val) {
                    ans = true;
                    result++;
                }
            } else if (root->left == nullptr && root->right != nullptr) {
                if (root->val == root->right->val) {
                    ans = true;
                    result++;
                }
            } else {
                ans = true;
                result++;
            }
        }
        return ans;
    }

    int closestValue(TreeNode *root, double target) {
        vector<int> nodes;
        backtracking(root, nodes);
        int det = 0x3f3f3f3f;
        int ops = -1;
        for (int i = 0; i < nodes.size(); i++) {
            if (abs(target - nodes[i]) < det) {
                det = abs(target - nodes[i]);
                ops = i;
            }
        }
        return nodes[ops];
    }

    void backtracking(TreeNode *root, vector<int> &nodes) {
        if (root == nullptr) {
            return;
        }
        backtracking(root, nodes);
        nodes.push_back(root->val);
        backtracking(root, nodes);
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) { //前序加中序

    }

    void preOrder(TreeNode *root, string &path) {
        if (root == nullptr) {
            return;
        }
        path.push_back( )
        preOrder(root->left, path);
        preOrder(root->right, path);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {

    }
};

int main() {

    return 0;
}