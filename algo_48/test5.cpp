#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 10e9 + 7;

ll mo(ll n) { return (n % mod + mod) % mod; }

ll dynamical(int i, int n, int p, set<int> &unVis, int free) {
    if (i >= n) {
        return 1;
    }
    ll ans = 0;
    if (free == 1) {
        unVis.erase(1);
        int odd = mo(dynamical(i + 1, n, 1, unVis, 0));
        unVis.insert(1);
        unVis.erase(2);
        int even = mo(dynamical(i + 1, n, 2, unVis, 0));
        unVis.insert(2);
        ans = mo((n - n / 2) * odd + n / 2 * even);
    } else {
        int odd_count = 0;
        int even_count = 0;
        int odd = 0;
        int even = 0;
        int cur = 0;
        for (const auto &v: unVis) {
            if (v * p % 2 == 0) {
                if (v % 2 != 0) {
                    if (odd == 0) odd = v;
                    odd_count++;
                } else {
                    if (even == 0) even = v;
                    even_count++;
                }
            }
        }
        //奇数
        if (odd_count != 0) {
            unVis.erase(odd);
            ans = mo(odd_count * mo(dynamical(i + 1, n, odd, unVis, 0)));
            unVis.insert(odd);
        }
        if (even_count != 0) {
            unVis.erase(even);
            ans += mo(even_count * mo(dynamical(i + 1, n, even, unVis, 0)));
            unVis.insert(even);
        }
    }

    return ans;
}

int solution(int n) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    set<int> unVis;
    for (int i = 1; i <= n; i++) {
        unVis.insert(i);
    }
    int res = dynamical(0, n, 0, unVis, 1);
    cout << "res = " << res << "\n";
    return res;
}

int main() {
    std::cout << (solution(2) == 2) << std::endl;
    std::cout << (solution(3) == 2) << std::endl;
    std::cout << (solution(5) == 12) << std::endl;
    std::cout << (solution(15) == 203212800) << std::endl;

//    std::cout << solution(15) << std::endl;
    return 0;
}