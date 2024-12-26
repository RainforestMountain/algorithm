#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if ((!(s[left] >= 'a' && s[left] <= 'z'))
                && (!(s[left] >= 'A' && s[left] <= 'Z'))
                && (!(s[left] >= '0' && s[left] <= '9'))) {
                left++;
            } else if ((!(s[right] >= 'a' && s[right] <= 'z'))
                       && (!(s[right] >= 'A' && s[right] <= 'Z'))
                       && (!(s[right] >= '0' && s[right] <= '9'))) {
                right--;
            } else if (tolower(s[left]) >= 'a' && tolower(s[right]) <= 'z'
                       && tolower(s[right]) >= 'a' && tolower(s[right]) <= 'z') {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            } else {
                if (s[left] != s[right]) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {

    Solution solution;
    cout << solution.isPalindrome("0P") << "\n";
    return 0;
}
