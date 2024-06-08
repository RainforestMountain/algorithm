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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> dq;
        dq.push(root);
        int flag = -1;//-1表示从左往右,1表示从右往左
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> path;
            for (int i = 0; i < size; i++) {
                root = dq.front();
                if (flag == -1) {
                    path.push_back(root->val);
                } else {
                    path.insert(path.begin(), root->val);
                }

                dq.pop();
                if (root->left != nullptr) {
                    dq.push(root->left);
                }
                if (root->right != nullptr) {
                    dq.push(root->right);
                }
            }
//            if (flag == 1) {
//                reverse(path.begin(), path.end());
//            }
            result.push_back(path);
            flag = -flag;
            path.clear();
        }
        return result;
    }
};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto result = solution.zigzagLevelOrder(root);
    for (const auto &path: result) {
        for (const auto &val: path) {
            cout << val << " ";
        }
        cout << "\n";
    }
    delete root;
    return 0;
}
