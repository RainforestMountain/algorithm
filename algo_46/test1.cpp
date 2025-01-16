
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int solution(std::vector<int> A) {
    // Edit your code here
    vector<int> counts(101);
    for (int i = 0; i < A.size(); i++) {
        counts[A[i]]++;
    }
    vector<int> prefix(101);
    prefix[0] = counts[0];
    for (int i = 1; i <= 100; i++) {
        prefix[i] = prefix[i - 1] + counts[i];
    }
    int res = 0;
    for (int i = 0; i <= 100; i++) {
        if (i == 0) {
            if (prefix[i] > prefix[100] - prefix[0]) {
                res += counts[i];
            }
        } else if (i == 100) {
            if (prefix[100] > 0) {
                res += counts[i];
            }
        } else {
            if (prefix[i] > prefix[100] - prefix[i]) {
                res += counts[i];
            }
        }
    }

    cout << "res = " << res << "\n";
    return res;
}

int main() {
    // Add your test cases here
    std::cout << (solution({100, 100, 100}) == 3) << std::endl;
    std::cout << (solution({2, 1, 3}) == 2) << std::endl;
    std::cout << (solution({30, 1, 30, 30}) == 3) << std::endl;
    std::cout << (solution({19, 27, 73, 55, 88}) == 3) << std::endl;
    std::cout << (solution({19, 27, 73, 55, 88, 88, 2, 17, 22}) == 5) << std::endl;
    return 0;
}
