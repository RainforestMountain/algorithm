#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 10e6 + 1;
int parent[N];

struct union_set {
    vector<int> elem;

    union_set(int n) {
        elem = vector<int>(n + 1, -1);
    }

    void merge() {

    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        parent[v] = u;
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            root = i;
            break;
        }
    }
    while (m--) {
        char ch;
        int v;
        cin >> ch >> v;
        if (ch == 'P') {
            int tmp = v;
            int h = 0;
            while (parent[tmp] != root || parent[tmp] != 0) {
                h++;
                tmp = parent[tmp];
            }
            root =
                    cout << h << "\n";
        } else {

        }
    }
}


int main() {


    return 0;
}
