#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        map<string, int> mp = {{"CM", 900},
                               {"M",  1000},
                               {"CD", 400},
                               {"D",  500},
                               {"XC", 90},
                               {"C",  100},
                               {"XL", 40},
                               {"L",  50},
                               {"IX", 9},
                               {"X",  10},
                               {"IV", 4},
                               {"V",  5},
                               {"I",  1}};
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n;) {
            if (i < n - 1) {
                string tmp = string(1, s[i]) + string(1, s[i + 1]);
                if (mp.find(tmp) != mp.end()) {
                    sum += mp[tmp];
                    i += 2;
                    continue;
                }
            }
            if (i < n) {
                string tmp = string(1, s[i]);
                if (mp.find(tmp) != mp.end()) {
                    sum += mp[tmp];
                }
                i++;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("MCMXCIV") << "\n";

    return 0;
}
