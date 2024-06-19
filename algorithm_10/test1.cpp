#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> array(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    queue<int> q;
    q.push(x);
    vector<bool> visited(n + 1);
    visited[x] = true;
    int minstep = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int level = q.front();
            q.pop();
            //上和下
            for (int j = 0; j < 2; j++) {
                int nlevel;
                if (j == 0) {
                    nlevel = level - array[level];
                } else {
                    nlevel = level + array[level];
                }
                if (nlevel >= 1 && nlevel <= n && !visited[nlevel]) {
                    if (nlevel == y) {
                        cout << minstep + 1 << "\n";
                        return 0;
                    }
                    q.push(nlevel);
                    visited[nlevel] = true;
                }
            }
        }
        minstep++;
    }
    cout << -1 << "\n";
    return 0;
}
