#include <bits/stdc++.h>
#include <vector>

using namespace std;

std::string solution(std::string binary1, std::string binary2) {
    // Please write your code here
    int n = binary1.size();
    int m = binary2.size();
    vector<int> res(max(n, m) + 4, -1);
    int s = 0;
    int c = 0;
    int k = res.size() - 1;
    int i = n - 1, j = m - 1;
    for (; i >= 0 && j >= 0; i--, j--) {
        int s = binary1[i] - '0' + binary2[j] - '0' + c;
        if (s >= 2) {
            c = 1;
            s -= 2;
        } else {
            c = 0;
        }
        res[k] = s;
        k--;
    }
    while (i >= 0) {
        int s = binary1[i] - '0' + c;
        if (s >= 2) {
            c = 1;
            s -= 2;
        } else {
            c = 0;
        }
        res[k] = s;
        k--;
        i--;
    }
    while (j >= 0) {
        int s = binary2[j] - '0' + c;
        if (s >= 2) {
            c = 1;
            s -= 2;
        } else {
            c = 0;
        }
        res[k] = s;
        k--;
        j--;
    }
    if (c != 0) {
        res[k] = c;
        k--;
    }
    int sum = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == -1) {
            continue;
        }
        sum = sum * 2 + res[i];

    }
//    cout << "sum = " << sum << "\n";
    return to_string(sum);
}

int main() {
    // You can add more test cases here
//    std::cout << (solution("101", "110") == "11") << std::endl;
    std::cout << (solution("111111", "10100") == "83") << std::endl;
    std::cout << (solution("111010101001001011", "100010101001") == "242420") << std::endl;
    std::cout << (solution("111010101001011", "10010101001") == "31220") << std::endl;

    return 0;
}
