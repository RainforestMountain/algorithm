#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node() {}

    explicit Node(int val, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right) {}
};

//t是先序序列的根下标, 根下标在进入其他函数时不能回退,用引用, t就是全局变量
void buildTree(Node *&root, int l, int r, int &t, vector<int> &pre, vector<int> &in) {
    if (l > r) {
        return;
    }
    int index = 0;
    //在中序序列里面即子树找根
    for (int i = l; i <= r; i++) {
        if (in[i] == pre[t]) {
            index = i;
            break;
        }
    }
    if (index == 0) {
        return;
    }
    root = new Node(in[index]);
    t++;//左右子树的根需要++
    buildTree(root->left, l, index - 1, t, pre, in);
    buildTree(root->right, index + 1, r, t, pre, in);
}

//引用是起别名,即全局变量了,不会回退
void postOrder(Node *root, string &res) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->val + '0');
    res.push_back(' ');
}

void remove_tree(Node *root) {
    if (root == nullptr) {
        return;
    }
    remove_tree(root->left);
    remove_tree(root->right);
    delete root;
}

void solve() {
    int n;
    cin >> n;
    vector<int> pre(n + 1);
    vector<int> in(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
    }
    Node *root = nullptr;
    int t = 1;
    string res;
    buildTree(root, 1, n, t, pre, in);
    postOrder(root, res);
    res.pop_back();
    cout << res << "\n";
//    remove_tree(root);
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

