#include <bits/stdc++.h>

using namespace std;

//字典树
struct Trie {
    vector<Trie *> children;//子节点不保存字符, 获取具体存储字符是通过父节点的指针
    bool isEnd;//是否是单词的结尾, 为true说明是结尾
    Trie() {
        children = vector<Trie *>(128);
        isEnd = false;
    }

    void insert(string &word) {
        Trie *cur = this;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (cur->children[(int) ch] == nullptr) {
                cur->children[(int) ch] = new Trie();
            }
            cur = cur->children[(int) ch];
        }
        cur->isEnd = true;
    }

    bool search(string &word) {
        Trie *cur = this;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (cur->children[(int) ch] == nullptr) {//子节点没有这个字符
                return false;
            }
            cur = cur->children[(int) ch];
        }
        return cur->isEnd;//这个字符是不是单词的结尾, 是单词的结尾, 那么就有这个单词
    }

    bool startWith(string &prefix) {
        Trie *cur = this;
        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if (cur->children[(int) ch] == nullptr) {
                return false;
            }
            cur = cur->children[(int) ch];
        }
        return true;//不用判断有没有这个单词
    }

    vector<string> complete(string &prefix) {
        Trie *cur = this;
        string tp;
        if (!startWith(prefix)) {
            return {};
        }
        vector<string> result;
        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            tp.push_back(ch);
            cur = cur->children[(int) ch];
        }
        //获取子树所有情况, 即遍历,深度优先搜索dfs
        dfs(cur, tp, result);
        return result;
    }

    void dfs(Trie *root, string &path, vector<string> &result) {
        if (root->children.empty()) {
            return;
        }
        if (root->isEnd) {
            result.push_back(string(path));
        }
        for (int i = 0; i < 128; i++) {
            if (root->children[i] != nullptr) {
                path.push_back(char(i));
                dfs(root->children[i], path, result);
                path.pop_back();
            }
        }
    }

    ~Trie() {
        for (auto child: children) {
            if (child) {
                delete child;
            }
        }
    }
};

std::string solution(int num, std::vector<std::string> data, std::string input) {
    // Please write your code here
    Trie trie = Trie();
    for (int i = 0; i < data.size(); i++) {
        trie.insert(data[i]);
    }
    auto v = trie.complete(input);
    string res;
    for (int i = 0; i < v.size(); i++) {
        res.append(v[i]);
        if (i < v.size() - 1) {
            res.push_back(',');
        }
    }
//    cout << res << "\n";
    return res.empty() ? "-1" : res;
}

int main() {
    //  You can add more test cases here
    std::vector<std::string> testData1 = {"select", "from", "where", "limit", "origin_log_db", "event_log_table",
                                          "user_id", "from_mobile"};

    std::cout << (solution(8, testData1, "f") == "from,from_mobile") << std::endl;
    std::cout << (solution(8, testData1, "wh") == "where") << std::endl;
    std::cout << (solution(8, testData1, "z") == "-1") << std::endl;

    return 0;
}