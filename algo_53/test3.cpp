#include <bits/stdc++.h>

using namespace std;

bool solution(int n, vector<int> a, int x, int y) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            if (i == 0 && a[i + 1] == y) {
                return true;
            } else if (i == n - 1 && a[i - 1] == y) {
                return false;
            } else {
                return a[i + 1] == y || a[i - 1] == y;
            }
        }
    }

    return false;
}

int main() {
    cout << (solution(4, {1, 4, 2, 3}, 2, 4) == true) << endl;
    cout << (solution(5, {3, 4, 5, 1, 2}, 3, 2) == false) << endl;
    cout << (solution(6, {6, 1, 5, 2, 4, 3}, 5, 2) == true) << endl;
    return 0;
}