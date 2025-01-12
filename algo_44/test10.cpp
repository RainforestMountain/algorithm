#include <bits/stdc++.h>

using namespace std;

//dfs(u) u节点往下的划分情况种类数
pair<int, int> dfs(int u, vector<vector<int>> &g, vector<int> &gift, set<int> &s) {
    int ans = 1;
    bool isleaf = true;
    bool hasgift = false;
    for (const auto &v: g[u]) {
        if (s.find(v) != s.end()) {
            continue;
        }
        isleaf = false;
        s.insert(v);
        auto tmp = dfs(v, g, gift, s);
        if (tmp.first != 0) {
            hasgift = true;
            ans *= (1 + tmp.second);
        }
    }
    if (isleaf) {
        if (gift[u] == 0) {
            return {0, 0};
        } else {
            return {gift[u], 1};
        }
    }
    if (gift[u] == 0) {
        if (hasgift) {

        }
    }
}

int solution(int nodes, int decorations, std::vector<std::vector<int>> tree) {
    // Please write your code here
    //树形dp
    vector<vector<int>> g(nodes + 1);
    int root = 1;
    for (int i = 1; i < tree.size(); i++) {
        g[tree[i][0]].push_back(tree[i][1]);
        g[tree[i][1]].push_back(tree[i][0]);
    }
    set<int> s;
    s.insert(1);
    vector<int> gift(tree[0]);
    gift.insert(gift.begin(), 0);
    auto res = dfs(1, g, gift, s);
    cout << "res = " << res.second << "\n";
    return res.second;
}

int main() {
//    //  You can add more test cases here
//    std::vector<std::vector<int>> testTree1 = {{1, 0, 0, 0, 2, 3},
//                                               {1, 7},
//                                               {3, 7},
//                                               {2, 1},
//                                               {3, 5},
//                                               {5, 6},
//                                               {6, 4}};
//    std::vector<std::vector<int>> testTree2 = {{1, 0, 1, 0, 2},
//                                               {1, 2},
//                                               {1, 5},
//                                               {2, 4},
//                                               {3, 5}};
//
//    std::cout << (solution(7, 3, testTree1) == 3) << std::endl;
//    std::cout << (solution(5, 2, testTree2) == 0) << std::endl;

    string res = "hello";
    res.insert(res.size(), "a");
    cout << res << "\n";
    return 0;
}
