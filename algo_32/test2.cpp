#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string> &strings) {
        std::sort(strings.begin(), strings.end(), [](string &o1, string &o2) {
            if (o1.size() < o2.size()) {
                return true;
            } else if (o1.size() > o2.size()) {
                return false;
            } else {
                return o1[0] < o2[0];
            }
        });
        int maxL = strings[strings.size() - 1].size();
        vector<vector<string>> result;



    }

    void dfs()
};

int main() {


    return 0;

}