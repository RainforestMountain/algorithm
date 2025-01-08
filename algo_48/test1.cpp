
#include <bits/stdc++.h>

using namespace std;

std::string solution(const std::string &str1);

//以i为起点的前缀能否拓展成最后的字符串
bool dfs(string &s, int u, vector<int> &dp) {
    int n = s.size();
    if (u >= n - 1) {
        dp[u] = 1;
        return true;
    }
    if (dp[u] != -1) {
        return dp[u] == 1;
    }
    string tp1;
    string tp2;
    bool ans = false;
    for (int k = 1; u + k < n && k <= u + 1; k++) {
        tp1.insert(tp1.begin(), s[u - k + 1]);
        tp2.push_back(s[u + k]);
        if (tp1 == tp2) {
            ans = dfs(s, u + k, dp);
        }
        if (ans) {
            break;
        }
    }
    if (ans) {
        dp[u] = 1;
    } else {
        dp[u] = 0;
    }
    return ans;
}


std::string solution(const std::string &str1) {
    // Edit your code here
    int n = str1.size();
    string s = string(str1);
    vector<int> dp(n, -1);
    for (int i = 0; i < n - 2; i++) {
        dfs(s, i, dp);
    }

    for (int i = 0; i < n; i++) {
        if (dp[i] == 1) {
            return s.substr(0, i + 1);
        }
    }
    return s;
}

int main() {
    // Add your test cases here

    std::cout << (solution("abbabbbabb") == "ab") << std::endl;
    std::cout << (solution("abbbabbbb") == "ab") << std::endl;
    std::cout
            << (solution("jiabanbananananiabanbananananbananananiabanbananananbananananbananananbanananan") == "jiaban")
            << std::endl;
    std::cout << (solution(
            "selectecttectelectecttectcttectselectecttectelectecttectcttectectelectecttectcttectectcttectectcttectectcttect") ==
                  "select") << std::endl;
    std::cout << (solution("discussssscussssiscussssscussssdiscussssscussssiscussssscussssiscussssscussss") == "discus")
              << std::endl;

    return 0;
}
