
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int val = stack2.top();
        stack2.pop();
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {

//    Solution solution = Solution();
//    solution.push(3);
//    solution.push(4);
//    solution.push(7);
//    cout << solution.pop() << "\n";

    double complex = 0;
    int n = 100000;
    for (int i = 1; i <= n; i++) {
        complex += 1.0 / i;
    }
//    cout << complex * n << "\n";

    printf("%.1f\n", complex * n);
    return 0;
}