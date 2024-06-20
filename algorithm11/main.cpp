#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct good {
    double weight;
    double value;
    int index;

    bool operator<(const good &o) const {
        return value / weight > o.value / o.weight;
    }
};

struct Node {
    double a;
    double b;
    double rest;
    Node *parent;
    int level;
    int select;

    Node() {
        parent = nullptr;
        level = 0;
        a = 0;
        b = 0;
        rest = 0;
        select = 0;
    }

    explicit Node(double a, double b, double rest, int level, int select) {
        this->a = a;
        this->b = b;
        this->rest = rest;
        this->level = level;
        parent = nullptr;
        this->select = select;
    }
};

bool cmp(Node *o1, Node *o2) {
    return o1->a + o1->b < o2->a + o2->b;
}

vector<vector<int>> bfs(vector<good> &goods, int w) {
    std::priority_queue<Node *, vector<Node *>, function<bool(Node *, Node *)>> q(cmp);
    Node *root = new Node(0, goods[1].value / goods[1].weight * w, w, 0, 0);
    q.push(root);
    double max = 0;
    Node *ans;
    vector<int> path;
    while (!q.empty()) {
        root = q.top();
        q.pop();
        //选和不选,哪一个物品根据节点所在层次决定
        int index = root->level + 1;
        if (index >= goods.size()) {
            continue;
        }
        for (int i = 0; i < 2; i++) {
            if (i == 0) {//选择
                if (root->rest < goods[index].weight) {
                    continue;
                } else {
                    double a = root->a + goods[index].value;
                    double r = (root->rest - goods[index].weight);
                    double k = goods[index + 1].value / goods[index + 1].weight;
                    double b = (index + 1 >= goods.size() ? 0 : r * k);
                    double rest = root->rest - goods[index].weight;
                    if (a + b >= max) {
                        Node *tmp = new Node(a, b, rest, index, 1);
                        tmp->parent = root;
                        q.push(tmp);
                        if (a > max) {
                            max = a;
                            ans = tmp;
                        }
                    }

                }
            } else {
                double a = root->a;
                double k = goods[index + 1].value / goods[index + 1].weight;
                double b = (index + 1 >= goods.size() ? 0 : root->rest * k);
                double rest = root->rest;
                if (a + b >= max) {
                    Node *tmp = new Node(a, b, rest, index, 0);
                    tmp->parent = root;
                    q.push(tmp);
                    if (a > max) {
                        max = a;
                        ans = tmp;
                    }
                }
            }
        }
    }
    while (ans->parent != nullptr) {
        if (ans->select == 1) {
            path.push_back(goods[ans->level].index);
        }
        ans = ans->parent;
    }
    vector<vector<int>> result;
    result.push_back(path);
    result.push_back(vector<int>(1, max));
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<good> goods(n + 1);
    for (int i = 1; i <= n; i++) {
        goods[i].index = i;
        cin >> goods[i].weight;
    }
    for (int i = 1; i <= n; i++) {
        cin >> goods[i].value;
    }
    sort(goods.begin() + 1, goods.end());
    auto path = bfs(goods, 10);
    for (const auto &item: path[0]) {
        cout << item << " ,";
    }
    cout << "maxValue = " << path[1][0] << "\n";

    return 0;
}