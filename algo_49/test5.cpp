#include <bits/stdc++.h>

using namespace std;


int solution(int N, std::vector<std::vector<int>> familiar_matrix) {
    // Please write your code here
    set<int> select;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int fi = 0, se = 0, th = 0, sum = INT_MAX;
        //找最小的
        if (select.find(i) != select.end()) {
            continue;
        }
        for (int j = 0; j < N; j++) {
            if (i == j || select.find(j) != select.end()) {
                continue;
            }
            for (int k = 0; k < N; k++) {
                if (j == k || select.find(k) != select.end()) {
                    continue;
                }
                if (sum > familiar_matrix[i][j] + familiar_matrix[i][k] + familiar_matrix[j][k]) {
                    sum = familiar_matrix[i][j] + familiar_matrix[i][k] + familiar_matrix[j][k];
                    fi = i, se = j, th = k;
                }
            }
        }
        select.insert(fi), select.insert(se), select.insert(th);
        ans += sum;
    }
    return ans;
}

int main() {
    //  You can add more test cases here
    std::vector<std::vector<int>> familiar_matrix1 = {{100, 78,  97},
                                                      {78,  100, 55},
                                                      {97,  55,  100}};
    std::vector<std::vector<int>> familiar_matrix2 = {
            {100, 56,  19,  87,  38,  61},
            {56,  100, 70,  94,  88,  94},
            {19,  70,  100, 94,  43,  95},
            {87,  94,  94,  100, 85,  11},
            {38,  88,  43,  85,  100, 94},
            {61,  94,  95,  11,  94,  100}};

    std::cout << (solution(3, familiar_matrix1) == 230) << std::endl;
    std::cout << (solution(6, familiar_matrix2) == 299) << std::endl;

    return 0;
}