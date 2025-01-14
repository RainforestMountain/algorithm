#include <bits/stdc++.h>

using namespace std;


void getMultiple(int factor, int l, int r, set<int> &ans) {
    int count = 0;
    for (int i = factor; i <= r; i += factor) {
        if (l <= i) {
            ans.insert(i);
        }
    }
}

int solution(int a, int b, int c, int l, int r) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    //倍增法
    set<int> ans;
    getMultiple(a, l, r, ans);
    getMultiple(b, l, r, ans);
    getMultiple(c, l, r, ans);

    return ans.size();
}

int main() {
//    std::cout << (solution(2, 3, 4, 1, 10) == 7) << std::endl;
//    std::cout << (solution(5, 7, 11, 15, 100) == 34) << std::endl;
//    std::cout << (solution(1, 1, 1, 1, 1000) == 1000) << std::endl;
    std::cout << (solution(1, 14, 7, 14, 17) == 4) << std::endl;
    return 0;
}