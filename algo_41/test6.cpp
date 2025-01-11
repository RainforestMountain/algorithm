#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
    vector<double> array;//直接插入排序
public:
    void Insert(int num) {
        if (array.empty()) {
            array.insert(array.begin(), num);
        } else {
            int i = 0;
            for (; i < array.size(); i++) {
                if (array[i] >= num) {
                    break;
                }
            }
            array.insert(array.begin() + i, num);
        }

    }

    double GetMedian() {
        if (array.empty()) {
            return -1;
        }
        if (array.size() % 2 == 1) {
            return array[array.size() / 2];
        } else {
            return (array[array.size() / 2 - 1] + array[array.size() / 2]) / 2;
        }
    }

};

int main() {
    Solution solution;
    solution.Insert(5);
    solution.Insert(3);
    solution.Insert(9);
    solution.Insert(14);
    solution.Insert(0);
    solution.Insert(7);
    solution.Insert(7);
    solution.Insert(7);
    cout << solution.GetMedian() << "\n";
    cout << 5 * 6 << "\n";
    return 0;
}