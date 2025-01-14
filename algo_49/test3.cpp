#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int n = s.size();
    if (n < 4) {
        return 0;
    }
    //找chhc串
    vector<int> ky;
    int l = 0;
    int r = 0;
    for (; r < n;) {
        if (r - l + 1 == 4) {
            if (s[r] == 'c' && s[l] == 'c' && s[l + 1] == 'h' && s[l + 2] == 'h' && s[l + 3] == 'c') {
                ky.push_back(l);
            }
            l++;
        }
        r++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

        }
    }
    return ans;
}

int main() {
    //cout << (solution("chhchhc") == 8) << endl;
    cout << (solution("chhcchhcchhc") == 43) << endl;
    cout << (solution("hhhh") == 0) << endl;
    return 0;
}