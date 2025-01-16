#include <bits/stdc++.h>

using namespace std;


int solution(int x, int y) {
    // Edit your code here
    int count = 0;
    if (x <= 0 && 0 <= y) {
        count++;
    }
    for (int pb = 1; pb <= 9; pb++) {
        int sum = 0;
        for (int digit = 1; digit <= 9; digit++) {
            sum = sum * 10 + pb;
            if (x <= sum && sum <= y) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Add your test cases here

    std::cout << (solution(1, 10) == 9) << std::endl;
    std::cout << (solution(2, 22) == 10) << std::endl;

    return 0;
}
