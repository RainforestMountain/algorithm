#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> m;
        m['1'] = '1';
        m['2'] = '5';
        m['3'] = 'a';
        m['4'] = 'a';
        m['5'] = '2';
        m['6'] = '9';
        m['7'] = 'a';
        m['8'] = '8';
        m['9'] = '6';
        m['0'] = '0';
        string tmp = string(num);
        std::reverse(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size(); i++) {
            tmp[i] = m[tmp[i]];
        }
        return tmp == num;

    }
};

int main() {
    Solution solution;

    cout << solution.isStrobogrammatic("888") << "\n";
    return 0;
}
