#include <bits/stdc++.h>

using namespace std;

std::string solution(int n, int k, std::vector<int> array_a) {
    // Please write your code here
    vector<int> tmp = vector<int>(array_a);
    tmp.insert(tmp.begin(), 0);
    vector<int> outstand;
    for (int i = 2; i <= n - 1; i++) {
        if (tmp[i - 1] < tmp[i] && tmp[i] > tmp[i + 1]) {
            outstand.push_back(i);
        }
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + tmp[i];
    }
    vector<vector<int>> result;
    for (int i = 0; i < outstand.size(); i++) {
        for (int j = i; j < outstand.size(); j++) {
            int sum = pre[outstand[j] + 1] - pre[outstand[i] - 1 - 1];
            if (sum <= k) {
                result.push_back({j - i + 1, outstand[i] - 1, outstand[j] + 1, sum});
            }
        }
    }
    sort(result.begin(), result.end(), [](auto o1, auto o2) {
        if (o1[0] > o2[0]) {
            return true;
        } else if (o1[0] < o2[0]) {
            return false;
        } else {
            if (o1[3] < o2[3]) {
                return true;
            } else if (o1[3] > o2[3]) {
                return false;
            } else {
                return o1[1] < o2[1];
            }
        }
    });
//    for (const auto &item: result) {
//        for (const auto &v: item) {
//            cout << v << " ";
//        }
//        cout << "\n";
//    }
    string ans = to_string(result[0][0]) + "," + to_string(result[0][1]) + "," + to_string(result[0][2]);
    return ans;
}

int main() {
    //  You can add more test cases here
    std::vector<int> array_a1 = {1000, 3000, 2000, 4000, 3000, 2000, 4000, 2000};
    std::vector<int> array_a2 = {2000, 5000, 2000, 1000, 4000, 2000, 4000, 3000};

    std::cout << (solution(8, 15000, array_a1) == "2,1,5") << std::endl;
    std::cout << (solution(8, 15000, array_a2) == "2,4,8") << std::endl;

    return 0;
}