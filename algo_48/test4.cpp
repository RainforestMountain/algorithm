#include <bits/stdc++.h>
#include <vector>

using namespace std;

int solution(const std::string &str1, const std::string &str2) {
    // Edit your code here
    int n = str1.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        //先考虑修改
        dp[i] = dp[i - 1] + (str1[i - 1] == str2[i - 1] ? 0 : 2);
        //再考虑交换
        if (str1[i - 1] != str2[i - 1]){
            for (int j = i - 1; j >= max(i - 3, 1); j--) {//最多考虑前面四个字符,
                //可以交换的情况是
                if (str1[i - 1] == str2[j - 1] && str1[j - 1] != str2[j - 1]) {
                    int inner_cost = 0;
                    if (i - 1 - (j - 1) == 2) {//中间只有一个字符
                        inner_cost += (str1[i - 2] == str2[i - 2] ? 0 : 2);
                    }
                    if (i - 1 - (j - 1) == 3) {
                        int x = i - 2, y = i - 3;
                        if (str1[x] == str2[y] && str1[y] == str2[x] && str1[x] != str2[x]) {//交换中间这两个
                            inner_cost += 1;
                        } else {//考虑两个都修改
                            inner_cost += (str1[x] != str2[x] ? 2 : 0) + (str1[y] != str2[y] ? 2 : 0);
                        }
                    }
                    dp[i] = min(dp[i], dp[j - 1] + (i - j) + inner_cost);
                }
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\ncost = " << dp[n] << "\n";
    return dp[n];
}

int main() {
    // Add your test cases here

//    std::cout << (solution("10001", "10000") == 2) << std::endl;
//    std::cout << (solution("100100", "100001") == 2) << std::endl;
//    std::cout << (solution("1010", "0011") == 3) << std::endl;
//    std::cout << (solution("1100", "0011") == 4) << std::endl;
    std::cout << (solution("1101000000001101", "0010110111100010") == 17) << std::endl;


    return 0;
}
