#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
/*
 * 最小栈
 */
class MinStack {
private:
    stack<int> depot;
    stack<int> minS;
public:
    MinStack() {
        depot = stack<int>();
        minS = stack<int>();
    }

    void push(int val) {
        //depot
        depot.push(val);
        //minS
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        }
    }

    void pop() {
        //depot
        if (depot.empty() || minS.empty()) {
            return;
        }
        int val = depot.top();
        depot.pop();
        if (val == minS.top()) {
            minS.pop();
        }
    }

    int top() {
        if (depot.empty()) {
            return -1;
        }
        return depot.top();
    }

    int getMin() {
        if (minS.empty()) {
            return -1;
        }
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << "\n";
    minStack.pop();
    cout << minStack.top() << "\n";
    cout << minStack.getMin() << "\n";

    return 0;
}