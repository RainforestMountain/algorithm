#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n, std::vector<int> a) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    //4
    vector<pair<int, int> > left(n);
    vector<pair<int, int>> right(n);
    left[0] = {0, 0};
    for (int i = 1; i < n; i++) {
        if (left[i - 1].second < a[i - 1]) {
            left[i] = {i - 1, a[i - 1]};
        } else {
            left[i] = left[i - 1];
        }
    }
    right[n - 1] = {n - 1, 0};
    for (int i = n - 2; i >= 0; i--) {
        if (right[i + 1].second < a[i + 1]) {
            right[i] = {i + 1, a[i + 1]};
        } else {
            right[i] = right[i + 1];
        }
    }
    left[0] = right[0];
    right[n - 1] = left[n - 1];
    int res = 0;
    for (int i = 0; i < n; i++) {
        int ls = (left[i].second + a[i]) * (min(abs(left[i].first - i), n - abs(left[i].first - i)));
        int rs = (right[i].second + a[i]) * (min(abs(right[i].first - i), n - abs(right[i].first - i)));
        res = max(res, max(ls, rs));
    }
    cout << "res = " << res << "\n";
    return res; // Placeholder return
}

int main() {
    std::cout << (solution(3, {1, 2, 3}) == 5) << std::endl;
    std::cout << (solution(4, {4, 1, 2, 3}) == 12) << std::endl;
    std::cout << (solution(5, {1, 5, 3, 7, 2}) == 24) << std::endl;
    return 0;
}