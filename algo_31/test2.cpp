#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> counts(10);
        int tmp = n;
        while (tmp > 0) { // tmp = 1234
            counts[tmp % 10]++;
            tmp /= 10;
        }

        for (int k = 0; k < 32; k++) {
            int num = 1 << k;
            vector<int> cur(10);
            while (num > 0) {
                cur[num % 10]++;
                num /= 10;
            }
            if (check(counts, cur)) {
                return true;
            }
        }
        return false;
    }

    bool check(vector<int> &arr1, vector<int> &arr2) {
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
//    bool dfs(int index, int cur, vector<int> &digits, unordered_set<int> &s) {
//        int n = digits.size();
//        if (index >= n) {
////            if (cur == lowbit(cur)) {
////                cout << cur << "\n";
////                return true;
////            }
////            return false;
//            return cur == lowbit(cur);
//        }
//        bool ans = false;
//        for (int i = 0; i < n; i++) {
//            if ((digits[i] == 0 && cur == 0) || (s.find(digits[i]) != s.end())) {
//                continue;
//            }
//            if (i != n - 1 && digits[i] == digits[i + 1]) {
//                ans = ans || dfs(index + 1, cur * 10 + digits[i], digits, s);
//            } else {
//                s.insert(digits[i]);
//                ans = ans || dfs(index + 1, cur * 10 + digits[i], digits, s);
//                s.erase(digits[i]);
//            }
//            if (ans) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    int lowbit(int n) {
//        return n & (-n);
//    }
};


int main() {

    Solution solution;
//    cout << (solution.lowbit(1000) == 1000) << "\n";
//    vector<int> digits = {1, 2, 0, 4};
//    unordered_set<int> s;
//    cout << solution.dfs(0, 0, digits, s) << "\n";
    cout << solution.reorderedPowerOf2(271612776) << "\n";
    return 0;
}
