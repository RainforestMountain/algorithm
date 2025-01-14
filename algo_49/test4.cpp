#include <bits/stdc++.h>

using namespace std;

vector<int> dynamical(int root, int fa, vector<vector<int>> &tree, vector<int> &nodes) {
    if (tree[root].empty()) {
        return {0, 0, 0};
    }
    int l = nodes[tree[root][0]], r = nodes[tree[root][1]];
    vector<int> left, right;
    if (l == 1) {
        left = dynamical(tree[root][0], root, tree, nodes);
    }
    if (r == 1) {
        right = dynamical(tree[root][1], root, tree, nodes);
    }
    if (l == 0 && r == 1) {
        if (right[1] == 0) {//右孩子没有炉
            if (right[2] == 0) {
                //右孩子没有点亮, 我就放一个
                return {right[0] + 1, 1, 1};
            } else {
                //右孩子点亮了, 可以选择不放, 如果当前节点是根那就必须放了
                if (fa == -1) {
                    return {right[0] + 1, 1, 1};
                } else {
                    return {right[0], 0, 0};
                }
            }
        } else {
            return {right[0], 0, 1};
        }
    } else if (l == 1 && r == 0) {
        if (left[1] == 0) {//左孩子没有炉
            if (left[2] == 0) {
                //左孩子没有温暖, 我就放一个
                return {left[0] + 1, 1, 1};
            } else {
                //左孩子温暖了,  可以选择不放, 如果当前节点是根那就必须放了
                if (fa == -1) {
                    return {left[0] + 1, 1, 1};
                } else {
                    return {left[0], 0, 0};
                }
            }
        } else {
            return {left[0], 0, 1};
        }
    } else if (l == 1 && r == 1) {
        if (left[2] == 0 || right[2] == 0) {
            //只要有一个没有温暖就要放
            return {left[0] + right[0] + 1, 1, 1};
        } else {
            if (left[1] == 1 || right[1] == 1) {
                //有一个有炉子, 当前节点就是温暖的
                return {left[0] + right[0], 0, 1};
            } else {
                if (fa == -1) {
                    return {left[0] + right[0] + 1, 1, 1};
                } else {
                    return {left[0] + right[0], 0, 0};
                }
            }
        }

    } else {
        return {0, 0, 0};
    }
}

int solution(std::vector<int> nodes) {
    // Please write your code here
    int n = nodes.size();
    int h = (int) log2(n + 1);
    vector<vector<int>> tree(n, vector<int>());
    queue<int> q;
    q.push(0);
    for (int i = 1; i < n;) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            //一次访问2个节点
            int root = q.front();
            if (i < n) {
                tree[root].push_back(i);
                if (nodes[i] == 1) {
                    q.push(i);
                }
            }
            if (i + 1 < n) {
                tree[root].push_back(i + 1);
                if (nodes[i + 1] == 1) {
                    q.push(i + 1);
                }
            }
            q.pop();
            i += 2;
        }
    }
    vector<int> res = dynamical(0, -1, tree, nodes);
    cout << "res = " << res[0] << "\n";
    return res[0];
}

int main() {
    //  You can add more test cases here
    std::vector<int> nodes1 = {1, 1, 0, 1, 1};
    std::vector<int> nodes2 = {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1};
    std::vector<int> nodes3 = {1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1};
    std::vector<int> nodes4 = {1, 1, 0, 1, 1, 1, 1};

    std::cout << (solution(nodes1) == 1) << std::endl;
    std::cout << (solution(nodes2) == 3) << std::endl;
    std::cout << (solution(nodes3) == 3) << std::endl;
    std::cout << (solution(nodes4) == 2) << std::endl;

    return 0;
}