#include <bits/stdc++.h>

using namespace std;

int func(int a, int b, int k) {
    return abs((a - b) * (a - b) - k * k);
}

int solution(int n, int m, int k, std::vector<int> &a, std::vector<int> &b) {
    // Please write your code here
    int res = 0x3f3f3f3f;
    set<int> bs;
    for (int j = 0; j < m; j++) {
        bs.insert(b[j]);
    }
    for (int i = 0; i < n; i++) {
        int v1 = a[i] + k;
        int v2 = a[i] - k;
        auto it1 = bs.lower_bound(v1);
        if (it1 != bs.end()) {
            int sum1 = func(a[i], *it1, k), sum2 = func(a[i], *(++it1), k);
            it1--, it1--;
            int sum3 = func(a[i], *it1, k);
            res = min(res, min(sum1, min(sum2, sum3)));
        }
        auto it2 = bs.lower_bound(v2);
        if (it2 != bs.end()) {
            int sum1 = func(a[i], *it2, k), sum2 = func(a[i], *(++it2), k);
            it2--, it2--;
            int sum3 = func(a[i], *it2, k);
            res = min(res, min(sum1, min(sum2, sum3)));
        }
    }
    cout << "res = " << res << "\n";
    return res;
}

int main() {
    // You can add more test cases here
    // case 1
    std::vector<int> a1 = {5, 3, 4, 1, 2};
    std::vector<int> b1 = {0, 6, 7, 9, 8};
    std::cout << (solution(5, 5, 1, a1, b1) == 0) << std::endl;

    //case 2
    std::vector<int> a2 = {5, 3, 4, 1, 2};
    std::vector<int> b2 = {0, 6, 7, 9, 8};
    std::cout << (solution(5, 5, 0, a2, b2) == 1) << std::endl;

    // case 3
//    std::vector<int> a3 = {5, 3, 4, 1, 2};
//    std::vector<int> b3 = {0, 6, 7, 9, 8, 11};
//    std::cout << (solution(5, 6, 3, a3, b3) == 0) << std::endl;
    std::vector<int> a3 = {3, 19, 23, 2, 13, 24, 23, 9, 1, 3, 16, 17, 6, 8, 13, 10, 15, 6, 4, 10, 18};
    std::vector<int> b3 = {22, 6, 19, 18, 13, 25, 17, 11};
    std::cout << (solution(a3.size(), b3.size(), 25, a3, b3) == 49) << std::endl;

    return 0;
}
