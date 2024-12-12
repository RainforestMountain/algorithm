#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    map<char, char> m;

    vector<string> findStrobogrammatic(int n) {
        //数位dp
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        m['0'] = '0';
        vector<char> digits = {'0', '1', '6', '8', '9'};
        dfs(digits, "", 0, n, false);
        return result;
    }

    vector<string> result;

    //free表示是否可以自由选择5个数, 当n > 1, 第一位不能是0
    void dfs(vector<char> &digits, string num, int len, int n, int free) {
        if (len == n) {
            if (check(num)) result.push_back(num);
            return;
        }
        if (!free && n > 1) {
            //1,6,8,9
            for (int i = 1; i < digits.size(); i++) {
                num.push_back(digits[i]);
                dfs(digits, num, len + 1, n, true);
                num.erase(num.end() - 1);
            }
        } else {
            for (int i = 0; i < digits.size(); i++) {
                num.push_back(digits[i]);
                dfs(digits, num, len + 1, n, true);
                num.erase(num.end() - 1);
            }
        }
    }

    bool check(string &num) {
        string tmp = string(num);
        std::reverse(tmp.begin(), tmp.end());
        for (int i = 0; i < num.size(); i++) {
            tmp[i] = m[tmp[i]];
        }
        return tmp == num;
    }
};

int main() {

//    string num = "1234";
//    num.erase(num.end() - 1);
//    cout << num << "\n";

    Solution solution;
    auto res = solution.findStrobogrammatic(3);
    std::for_each(res.begin(), res.end(), [](auto val) {
        cout << val << "\n";
    });

    return 0;
}