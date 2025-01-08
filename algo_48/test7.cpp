#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int &i, int &j) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            if (i == -1) {
                i = l;
            } else if (j == -1) {
                j = l;
            }
        }
        l++;
        r--;
    }
    if (i != -1 || j != -1) {
        return false;
    }
    return true;
}

std::string solution(const std::string &s) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int i = -1, j = -1;
    string src = string(s);
    if (isPalindrome(src, i, j)) {
        //去更改左边不是a的字符
        for (int t = 0; t < s.size() / 2 + 1; t++) {
            if (src[t] != 'a') {
                //修改
                src[t] = src[src.size() - 1 - t] = 'a';
                break;
            }
        }
    } else {
        //cout << "i = " << i << " j = " << j << "\n";
        if (i != -1 && j == -1) {
            if (src[i] != 'a' && src[src.size() - 1 - i] != 'a') {
                src[i] = src[src.size() - 1 - i] = 'a';
            } else {
                src[i] = src[src.size() - 1 - i] = min(src[i], src[src.size() - 1 - i]);
                if (src.size() % 2 == 1) {
                    src[src.size() / 2] = 'a';
                }
            }

        } else {
            src[i] = min(src[i], src[src.size() - 1 - i]);
            src[src.size() - 1 - i] = src[i];
            src[j] = min(src[j], src[src.size() - 1 - j]);
            src[src.size() - 1 - j] = src[j];
        }
    }
    return src;
}

int main() {
    std::cout << (solution("acca") == "aaaa") << std::endl;
    std::cout << (solution("racecar") == "aacecaa") << std::endl;
    std::cout << (solution("fecdef") == "feaaef") << std::endl;
    std::cout << (solution("acccaacaacccc") == "acccaaaaaccca") << std::endl;
    std::cout << (solution("vhkav") == "vaaav") << std::endl;
    return 0;
}