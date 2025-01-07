#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        // write code here
        stack<int> st;
        string tmp = transfrom(s);
        for (int i = 0; i < tmp.size(); i++) {
            if (isdigit(tmp[i])) {
                if (i > 0 && isdigit(tmp[i - 1])) {
                    int sum = st.top() * 10 + tmp[i] - '0';
                    st.pop();
                    st.push(sum);
                } else {
                    st.push(tmp[i] - '0');
                }
            } else if (tmp[i] != '#') {
                if (st.size() >= 2) {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    int res = 0;
                    switch (tmp[i]) {
                        case '+':
                            res = a + b;
                            break;
                        case '-':
                            res = a - b;
                            break;
                        case '*':
                            res = a * b;
                            break;
                    }
                    st.push(res);
                }
            }
        }
        return st.top();
    }

    string transfrom(string s) {
        string res;
        stack<char> sign;
        int n = s.size();
        map<char, int> order;
        order['+'] = 1;
        order['-'] = 1;
        order['*'] = 2;
        order['('] = 0;
        order[')'] = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                if (i > 0 && isdigit(s[i - 1])) {
                    res.erase(res.end() - 1);
                }
                res.push_back(s[i]);
                res.push_back('#');
            } else if (s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '(' || s[i] == ')') {
                if (sign.empty() || order[s[i]] > order[sign.top()] || s[i] == '(') {
                    sign.push(s[i]);
                } else {
                    while (!sign.empty() && order[s[i]] <= order[sign.top()]) {
                        if (s[i] == ')' && sign.top() == '(') {
                            sign.pop();
                            break;
                        }
                        char ch = sign.top();
                        sign.pop();
                        res.push_back(ch);
                    }
                    if (s[i] != ')') {
                        sign.push(s[i]);
                    }
                }
            }
        }
        while (!sign.empty()) {
            if (sign.top() != ')') {
                res.push_back(sign.top());
            }
            sign.pop();
        }
        return res;

    }
};

int main() {
    Solution solution;
    cout << solution.transfrom("((10+2)*10-(100-(10+20*10-(2*3)))*10*1*2)-2") << "\n";
    cout << solution.solve("((10+2)*10-(100-(10+20*10-(2*3)))*10*1*2)-2") << "\n";
    return 0;
}
