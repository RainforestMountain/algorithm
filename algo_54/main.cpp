#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) {
            return false;
        }
        map<char, int> mp_s;
        map<char, int> mp_t;
        for (int i = 0; i < n; i++) {
            mp_s[s[i]]++;
        }
        for (int i = 0; i < m; i++) {
            mp_t[t[i]]++;
        }
        if (mp_s.size() != mp_t.size()) {
            return false;
        } else {
            for (auto it1 = mp_s.begin(), it2 = mp_t.begin(); it1 != mp_s.end() && it2 != mp_t.end(); it1++, it2++) {
                if (it1->first != it2->first) {
                    return false;
                }
                if (it1->second != it2->second) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {

    return 0;
}
