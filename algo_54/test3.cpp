
#include <bits/stdc++.h>

using namespace std;

//豆包, 105, 最佳人选
std::string solution(int m, int n, std::string target,
                     std::vector<std::string> &array) {
    // Edit your code here
    int differences = 0x3f3f3f3f;
    vector<int> diff(n);
    for (int t = 0; t < n; t++) {
        string password = array[t];
        int sum = 0;
        for (int i = 0; i < m; i++) {
            if (target[i] == 'A' && password[i] == 'E' || target[i] == 'E' && password[i] == 'A'
                || target[i] == 'B' && password[i] == 'D' || target[i] == 'D' && password[i] == 'B'
                || target[i] == 'C' && password[i] == 'E' || target[i] == 'E' && password[i] == 'C'
                || target[i] == 'B' && password[i] == 'E' || target[i] == 'E' && password[i] == 'B') {
                sum = 0x3f3f3f3f;
                break;
            } else {
                sum += abs(password[i] - target[i]);
            }
        }
        diff[t] = sum;
        if (sum < differences) {
            differences = sum;
        }
    }
    if (differences == 0x3f3f3f3f) {
        return "None";
    } else {
        string res;
        for (int t = 0; t < n; t++) {
            if (diff[t] == differences) {
                res.append(array[t]);
                res.append(" ");
            }
        }
        res.pop_back();
        //cout << "res = " << res << "\n";
        return res;
    }

}

int main() {
    // Add your test cases here
    std::vector<std::string> matrix = {"AAAAAA", "BBBBBB", "ABDDEB"};
    std::cout << (solution(6, 3, "ABCDEA", matrix) == "ABDDEB") << std::endl;

    return 0;
}
