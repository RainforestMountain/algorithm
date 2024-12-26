#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    stack<int> registry;
    stack<int> minSt;
public:
    void push(int value) {
        if (registry.empty()) {
            registry.push(value);
            minSt.push(value);
            return;
        }
        registry.push(value);
        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        }
    }

    void pop() {
        if (!registry.empty()) {
            int value = registry.top();
            if (value == minSt.top()) {
                minSt.pop();
            }
            registry.pop();
        }
    }

    int top() {
        if (!registry.empty()) {
            return registry.top();
        }
        return -1;
    }

    int min() {
        if (!minSt.empty()) {
            return minSt.top();
        }
        return -1;
    }
};

int main() {
    Solution solution;
    solution.push(5);
    solution.push(3);
    solution.push(1);
    solution.push(1);
    cout << solution.min() << "\n";
    solution.pop();
    cout << solution.min() << "\n";
    solution.pop();
    cout << solution.min() << "\n";
    return 0;
}
