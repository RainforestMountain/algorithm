#include <bits/stdc++.h>

using namespace std;

string add(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    int s = 0, c = 0;
    string res;
    int i, j;
    for (i = n - 1, j = m - 1; i >= 0 && j >= 0; i--, j--) {
        s = s1[i] - '0' + s2[j] - '0' + c;
        c = (s >= 10 ? 1 : 0);
        s = (s >= 10 ? s -= 10 : s);
        res.insert(res.begin(), s + '0');
    }
    while (i >= 0) {
        s = s1[i] - '0' + c;
        c = (s >= 10 ? 1 : 0);
        s = (s >= 10 ? s -= 10 : s);
        res.insert(res.begin(), s + '0');
        i--;
    }
    while (j >= 0) {
        s = s2[j] - '0' + c;
        c = (s >= 10 ? 1 : 0);
        s = (s >= 10 ? s -= 10 : s);
        res.insert(res.begin(), s + '0');
        j--;
    }
    if (c != 0) {
        res.insert(res.begin(), c + '0');
    }
    return res;
}

int solution(std::string string1, std::string string2) {
    // Please write your code here
    string res = add(string1, string2);
    int n = res.size();
    int ma_v = -1, mi_v = 10;
    for (int i = 0; i < n; i++) {
        ma_v = max(res[i] - '0', ma_v);
        mi_v = min(res[i] - '0', mi_v);
    }
    vector<int> mi_set, ma_set;
    for (int i = 0; i < n; i++) {
        if (res[i] - '0' == mi_v) mi_set.push_back(i);
        if (res[i] - '0' == ma_v) ma_set.push_back(i);
    }
    int ans = INT_MAX;
    for (int i = 0; i < mi_set.size(); i++) {
        for (int j = 0; j < ma_set.size(); j++) {
            ans = min(ans, max(abs(mi_set[i] - ma_set[i]) - 1, 0));
        }
    }
    //cout << "res = " << res << " ans = " << ans << "\n";
    return ans;
}

int main() {
    //  You can add more test cases here
    std::cout << (solution("111", "222") == 0) << std::endl;
    std::cout << (solution("111", "34") == 1) << std::endl;
    std::cout << (solution("5976762424003073", "6301027308640389") == 6) << std::endl;
    std::cout << (solution("999", "1") == 0) << std::endl;

    return 0;
}