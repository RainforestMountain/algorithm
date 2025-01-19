
#include <bits/stdc++.h>

using namespace std;

//由sg定理得到,不是每个都是异或和
bool nim(vector<int> &heap) {
    int sum = 0;
    for (int i = 0; i < heap.size(); i += 2) {
        sum ^= heap[i];
    }
    return sum != 0;
}

void solve() {
    vector<int> A;

    int v;
    while (cin >> v) {
        A.push_back(v);
        if (cin.peek() == ' ') {
            continue;
        } else {
            break;
        }
    }
    int n = A.size();
    vector<int> heap(n - 1);//有n - 堆
    for (int i = 0; i < n - 1; i++) {
        heap[i] = A[i + 1] - A[i] - 1;
    }
    int sum = 0;
    if (!nim(heap)) {
        cout << -1 << "\n";
        return;
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n - 1; i++) {
        //如果可以移动
        //移动1到j个台阶
        for (int j = 1; j <= heap[i]; j++) {
            heap[i] -= j;
            //同时后面堆数量也会变化
            if (i != 0) {
                heap[i - 1] += j;
            }
            bool ans = nim(heap);//操作后 下一个轮是对手先手了, 所以对手的输状态为P
            if (!ans) {
                cout << A[i] << " " << A[i] + j << "\n";
                return;
            }
            if (i != 0) {
                heap[i - 1] -= j;
            }
            heap[i] += j;
        }
    }
    cout << -1 << "\n";
}

int main() {
    solve();

    return 0;
}