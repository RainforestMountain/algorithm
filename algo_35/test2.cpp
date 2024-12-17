#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;
        for (const auto &ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (!st.empty()) {
                    char top = st.top();
                    st.pop();
                    if (top == '(' && ch != ')') {
                        return false;
                    } else if (top == '[' && ch != ']') {
                        return false;
                    } else if (top == '{' && ch != '}') {
                        return false;
                    }
                } else {
                    return false;
                }

            }
        }
        return true;
    }
};

int main() {


    return 0;
}