#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            result.emplace_back(i + 1);
            result[i][0] = 1;
            result[i][result[i].size() - 1] = 1;
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 1; j < result[i].size() - 1; j++) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    auto res = solution.generate(11);
    for (const auto &item: res) {
        for (const auto &v: item) {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}
