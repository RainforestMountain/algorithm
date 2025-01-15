#include <bits/stdc++.h>

using namespace std;

map<char, int> prior = {{'+', 1},
                        {'-', 1},
                        {'*', 2},
                        {'/', 2}};

int solution(std::string expression) {
    // Please write your code here
    stack<char> op;
    string suffix;
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            suffix.push_back(expression[i]);
            suffix.push_back('#');
        } else {
            if (op.empty() || expression[i] == '(') {
                op.push(expression[i]);
            } else {
                if (expression[i] == ')') {
                    while (!op.empty() && op.top() != '(') {
                        suffix.push_back(op.top());
                        op.pop();
                    }
                    if (!op.empty()) {
                        op.pop();
                    }
                } else {
                    if (op.top() == '(' && prior[op.top()] < prior[expression[i]]) {
                        op.push(expression[i]);
                    } else {
                        while (!op.empty() && op.top() != '(' && prior[op.top()] >= prior[expression[i]]) {//(5*6*7+5)
                            suffix.push_back(op.top());
                            op.pop();
                        }
                        op.push(expression[i]);
                    }
                }
            }
        }
    }
    while (!op.empty()) {
        suffix.push_back(op.top());
        op.pop();
    }
    stack<int> res;
    for (int i = 0; i < suffix.size();) {
        if (isdigit(suffix[i])) {
            int num = 0;
            while (i < suffix.size() && suffix[i] != '#') {
                num = num * 10 + suffix[i] - '0';
                i++;
            }
            i++;
            res.push(num);
        } else {
            if (res.size() >= 2) {
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                int v = 0;
                switch (suffix[i]) {
                    case '+':
                        v = b + a;
                        break;
                    case '-':
                        v = b - a;
                        break;
                    case '*':
                        v = b * a;
                        break;
                    case '/':
                        v = b / a;
                        break;
                }
                res.push(v);
            }
            i++;
        }
    }

//    cout << suffix << "\n";
    return res.top();
}

int main() {
    // You can add more test cases here
    std::cout << (solution("1+1") == 2) << std::endl;
    std::cout << (solution("3+4*5/(3+2)") == 7) << std::endl;
    std::cout << (solution("4+2*5-2/1") == 12) << std::endl;
    std::cout << (solution("(1+(4+5+2)-3)+(6+8)") == 23) << std::endl;
    return 0;
}