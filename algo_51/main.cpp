#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        //kmp
        //最长相等前后缀
        //sadbutsad
        //sad
        vector<int> next = getNext(needle);
        int i = 0;
        int j = -1;//j + 1 回退的下标
        for (; i < haystack.size(); i++) {
            //要么找到与haystack的i位置匹配的needle的回退下标j + 1,
            // 要么彻底找不到,j == -1, 让i+1, 写在循环体条件那里来
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];//回退操作
            }
            if (haystack[i] == needle[j + 1]) {//匹配成功,i,j同时增加
                j++;
            }
            if (j == (needle.size() - 1)) {//匹配成功
                return i - needle.size() + 1;
            }
        }
        return -1;
    }

    //动态规划求解
    vector<int> getNext(string t) {
        int n = t.size();
        vector<int> dp(n);
        int j = -1;//这样最长公共前后缀的长度是少1,方便之后匹配的回退处理
        dp[0] = j;//方便回退到0的时候,及时退出循环
        for (int i = 1; i < n; i++) {
            //自己匹配自己
            //回退
            while (j >= 0 && t[j + 1] != t[i]) {//直到回退到0,最初开始的时候
                j = dp[j];
            }
            if (t[j + 1] == t[i]) {
                j++;
            }
            dp[i] = j;
        }
        return dp;
    }
};

int main() {

    Solution solution = Solution();
//    auto next = solution.getNext("aabaaf");
//    for (int i = 0; i < next.size(); i++) {
//        cout << next[i] << " ";
//    }
//    cout << "\n";
    cout << solution.strStr("sadbutsad", "sad") << "\n";
    return 0;
}

