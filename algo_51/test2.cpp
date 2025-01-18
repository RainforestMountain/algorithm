#include <bits/stdc++.h>

using namespace std;


std::string solution(int n, std::vector<int> sums) {
    // Please write your code here
    int len = sums.size();
    return "-2";
}

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r &&
                   !(('A' <= s[l] && s[l] <= 'Z') || ('a' <= s[l] && s[l] <= 'z') || ('0' <= s[l] && s[l] <= '9'))) {
                l++;
            }
            while (l < r &&
                   !(('A' <= s[r] && s[r] <= 'Z') || ('a' <= s[r] && s[r] <= 'z') || ('0' <= s[r] && s[r] <= '9'))) {
                r--;
            }
            if ('0' <= s[l] && s[l] <= '9') {
                if (!('0' <= s[r] && s[r] <= '9')) {
                    return false;
                }
                if ('0' <= s[r] && s[r] <= '9' && s[l] != s[r]) {
                    return false;
                }
            } else if ('0' <= s[r] && s[r] <= '9') {
                if (!('0' <= s[l] && s[l] <= '9')) {
                    return false;
                }
            } else {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
            }
            l++;
            r--;
        }
        return true;
    }
};

int main() {

    Solution solution = Solution();
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << "\n";
//    // You can add more test cases here
//    std::vector<int> sums1 = {1269, 1160, 1663};
//    std::vector<int> sums2 = {1, 1, 1};
//    std::vector<int> sums3 = {226, 223, 225, 224, 227, 229, 228, 226, 225, 227};
//    std::vector<int> sums4 = {-1, 0, -1, -2, 1, 0, -1, 1, 0, -1};
//    std::vector<int> sums5 = {79950, 79936, 79942, 79962, 79954, 79972, 79960, 79968, 79924, 79932};
//
//    std::cout << (solution(3, sums1) == "383 777 886") << std::endl;
//    std::cout << (solution(3, sums2) == "Impossible") << std::endl;
//    std::cout << (solution(5, sums3) == "111 112 113 114 115") << std::endl;
//    std::cout << (solution(5, sums4) == "-1 -1 0 0 1") << std::endl;
//    std::cout << (solution(5, sums5) == "39953 39971 39979 39983 39989") << std::endl;

    return 0;
}