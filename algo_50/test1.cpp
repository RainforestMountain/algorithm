#include <bits/stdc++.h>

using namespace std;


int solution(int m, int w, int p, int n) {
    // Please write your code here
    int ma = n / (m * w) + 1;
    int ans = ma;

    for (int i = 0; i <= ma -1; i++) {
        int mt = m, wt = w, rest = 0;
        for (int j = 1; j <= i; j++) {
            if (mt >= 10000) {
                break;
            }
            rest += mt * wt;
            if (rest >= p) {
                int det = rest / p;//不一定全部加上
                while (det--) {
                    if (mt > wt) {
                        wt += 1;
                    } else if (mt <= wt) {
                        mt += 1;
                    }
                    rest -= p;
                    ans = min(ans, i +
                                   ((n - rest) % (mt * wt) == 0 ? ((n - rest) / (mt * wt)) : ((n - rest) / (mt * wt) +
                                                                                              1)));
                }
            }
        }
        ans = min(ans, i +
                       ((n - rest) % (mt * wt) == 0 ? ((n - rest) / (mt * wt)) : ((n - rest) / (mt * wt) +
                                                                                  1)));
    }
    cout << "ans = " << ans << "\n";
    return ans;
}

int main() {
    //  You can add more test cases here
    //std::cout << (solution(3, 1, 2, 12) == 3) << std::endl;
    //std::cout << (solution(10, 5, 30, 500) == 8) << std::endl;
    //std::cout << (solution(3, 5, 30, 320) == 14) << std::endl;
    std::cout << (solution(1, 11, 1, 11) == 1) << std::endl;

    return 0;
}