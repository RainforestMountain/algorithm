#include <bits/stdc++.h>

using namespace std;

std::string solution(std::vector<int> &plates, int n) {
    // Please write your code here
    int l = 0;
    int r = 1;
    string ans;
    for (; r < n;) {
        if (plates[r - 1] == plates[r] - 1) {
            r++;
        } else {
            if (r - 1 - l + 1 >= 3) {
                ans.append(to_string(plates[l]) + "-" + to_string(plates[r - 1]));
            } else if (r - 1 - l + 1 == 2) {
                ans.append(to_string(plates[l]));
                ans.push_back(',');
                ans.append(to_string(plates[r - 1]));
            } else {
                ans.append(to_string(plates[l]));
            }
            ans.push_back(',');
            l = r;
            r++;
        }
    }
    if (r - 1 - l + 1 >= 3) {
        ans.append(to_string(plates[l]) + "-" + to_string(plates[r - 1]));
    } else if (r - 1 - l + 1 == 2) {
        ans.append(to_string(plates[l]));
        ans.push_back(',');
        ans.append(to_string(plates[r - 1]));
    } else {
        ans.append(to_string(plates[l]));
    }
    cout << ans << "\n";
    return ans;
}

int main() {
    //  You can add more test cases here
    std::vector<int> plates1 = {-3, -2, -1, 2, 10, 15, 16, 18, 19, 20};
    std::cout << (solution(plates1, 10) == "-3--1,2,10,15,16,18-20") << std::endl;

    std::vector<int> plates2 = {-6, -3, -2, -1, 0, 1, 3, 4, 5, 7,
                                8, 9, 10, 11, 14, 15, 17, 18, 19, 20};
    std::cout << (solution(plates2, 20) == "-6,-3-1,3-5,7-11,14,15,17-20")
              << std::endl;

    std::vector<int> plates3 = {1, 2, 7, 8, 9, 10, 11, 19};
    std::cout << (solution(plates3, 8) == "1,2,7-11,19") << std::endl;

    return 0;
}
