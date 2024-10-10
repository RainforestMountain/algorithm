#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//为了得到最大字典序,而不是一定要排序, 强行排序的字典序不一定比贪心的更大
//栈顶元素大于后面序列的最大值, 那么此时出栈会使字典序更大, 需要持续判断, 不止一个栈顶
//栈顶元素小于后面序列的最大值, 那么让后面的元素入栈会有利于字典序更大, 所以当前元素入栈
int main() {
    int n;
    cin >> n;
    vector<int> order(n + 1);
    vector<int> maxn(n + 1);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        order[i] = v;
    };
    maxn[n] = order[n];
    for (int i = n - 1; i >= 1; i--) {
        maxn[i] = max(maxn[i + 1], order[i]);
    }

    stack<int> s;
    vector<int> res(n + 1);
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && s.top() > maxn[i]) {
            res[j] = s.top();
            s.pop();
            j++;
        }
        s.push(order[i]);
    }
    while (!s.empty()) {
        res[j] = s.top();
        s.pop();
        j++;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }

    cout << "\n";
    return 0;
}
