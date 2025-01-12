#include <bits/stdc++.h>

using namespace std;

int main() {

    for (int i = 100; i < 1000; i++) {
        int a = i / 100 % 10;
        int b = i / 10 % 10;
        int c = i / 1 % 10;
        if (a * a * a + b * b * b + c * c * c == i) {
            cout << i << "\n";
        }
    }
    return 0;
}
