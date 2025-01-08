#include <bits/stdc++.h>
#include <vector>

using namespace std;

int na, ns, nd, nf;
int ta, ts, td, tf;

int check() {
    if (na <= ta && ns <= ts && nd <= td && nf <= tf) {
        return 1;
    }
    return -1;
}

void add(string &input, int &i) {
    switch (input[i]) {
        case 'A':
            ta++;
            break;
        case 'S':
            ts++;
            break;
        case 'D':
            td++;
            break;
        case 'F':
            tf++;
            break;
    }
}

int solution(std::string input) {
    // Please write your code here
    int n = input.size();
    int A = 0, S = 0, D = 0, F = 0;
    for (int i = 0; i < n; i++) {
        if (input[i] == 'A') A++;
        if (input[i] == 'S') S++;
        if (input[i] == 'D') D++;
        if (input[i] == 'F') F++;
    }
    int res = 0;
    na = max(A - n / 4, 0), ns = max(S - n / 4, 0);
    nd = max(D - n / 4, 0), nf = max(F - n / 4, 0);
    ta = 0, ts = 0, td = 0, tf = 0;
    int len = n;
    int left = 0, right = 0;
    for (; left < n; left++) {
        ta = 0, td = 0, ts = 0, tf = 0;
        for (right = left; right < n; right++) {
            if (check() == 1) {
                len = min(len, right - left);
            }
            add(input, right);
        }
        if (check() == 1) {
            len = min(len, right - left);
        }
    }
    cout << "len = " << len << "\n";
    return len;
}


int main() {
    //  You can add more test cases here
    std::cout << (solution("ADDF") == 1) << std::endl;
    std::cout << (solution("AFAFSSFDSFFF") == 3) << std::endl;
    return 0;
}