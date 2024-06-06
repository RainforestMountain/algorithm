#include <iostream>
#include <bits/stdc++.h>

class TreeNode {
public:
    int flag; // 标记初始的叶子节点为1,生成的节点是0
    double val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(double val) : flag(1), val(val), left(nullptr), right(nullptr) {}

    TreeNode(double val, int flag) : flag(flag), val(val), left(nullptr), right(nullptr) {}


};

// 按照权值大小排序,当权值相等时,叶子节点应该排在非叶子节点后面
bool cmp(TreeNode *&one, TreeNode *&other) {
    if (one->val < other->val) {
        return true;
    } else if (one->val > other->val) {
        return false;
    } else {
        if (one->flag == 1) {
            return false;
        } else if (other->flag == 1) {
            return true;
        } else {
            return true;
        }
    }
}


TreeNode *createTree(const std::vector<double> &array) {
    std::vector<TreeNode *> nodes;
    for (double val: array) {
        nodes.push_back(new TreeNode(val, 1));
    }

    while (nodes.size() > 1) {
        std::sort(nodes.begin(), nodes.end(), cmp);
        TreeNode *left = nodes[1];
        TreeNode *right = nodes[0];
        nodes.push_back(new TreeNode(left->val + right->val, 0));
        nodes.back()->left = left;
        nodes.back()->right = right;
        nodes.erase(nodes.begin() + 1);
        nodes.erase(nodes.begin());
    }
    TreeNode *root = nodes[0];
    for (TreeNode *node: nodes) {
        delete node; // 清理内存
    }
    return root;
}

void dfs(TreeNode *root, std::map<double, std::string> &result, std::string path = "") {
    if (root->left == nullptr && root->right == nullptr) {
        result[root->val] = path;
        return;
    }
    if (root->left != nullptr) {
        dfs(root->left, result, path + '0');
    }
    if (root->right != nullptr) {
        dfs(root->right, result, path + '1');
    }
}

std::map<double, std::string> haffmanCode(TreeNode *root) {
    std::map<double, std::string> result;
    dfs(root, result);
    return result;
}

int main() {
    std::vector<double> values = {0.01, 0.02, 0.03, 0.04, 0.07, 0.08, 0.09, 0.11, 0.20, 0.35};
    TreeNode *root = createTree(values);
    std::map<double, std::string> code = haffmanCode(root);

    for (const auto &pair: code) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    delete root; // 清理内存
    return 0;
}