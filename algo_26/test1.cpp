#include <iostream>
#include <bits/stdc++.h>
#include "FileRead.h"

using namespace std;


class Solution {
public:
    char temp[4];//temp数组是来读取的
    int tempIndex = 0;
    int count = 0;


    int read(char *buf, int n) {
        int bufIndex = 0;
        if (count > 0) {
            while (bufIndex < n && tempIndex < count) {
                buf[bufIndex++] = temp[tempIndex++];
            }
        }
        if (tempIndex == count) {
            tempIndex = 0;
            count = 0;
        }
        while (bufIndex < n) {
            count = read4(temp);
            if (count == 0) {
                break;
            }
            while (bufIndex < n && tempIndex < count) {
                buf[bufIndex++] = temp[tempIndex++];
            }
            if (tempIndex == count) {
                tempIndex = 0;
                count = 0;
            }
        }
        return bufIndex;
    }
};

int main() {
    vector<int> queries = {1, 2, 3};
    Solution solution;
    char buf[100];
    for (const auto &times: queries) {
        cout << solution.read(buf, times) << "\n";
    }
    return 0;
}