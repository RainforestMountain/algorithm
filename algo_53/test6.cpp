#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool dfs(int i, int curSum, vector<int> &bag, int target);

bool isTrade(vector<int> &bag, int target) {
    return dfs(0, 0, bag, target);
}

bool dfs(int i, int curSum, vector<int> &bag, int target) {
    int n = bag.size();
    if (curSum == target) {
        return true;
    }
    if (i >= n) {
        return false;
    }
    //选和不选, 选了, 有加, 有减
    bool ans = dfs(i + 1, curSum + bag[i], bag, target);
    if (ans) {
        return ans;
    }
    ans = dfs(i + 1, curSum - bag[i], bag, target);
    if (ans) {
        return ans;
    }
    ans = dfs(i + 1, curSum, bag, target);
    return ans;
}

std::string solution(int V, int W) {
    // Edit your code here
    int top = (int) (log(W) / log(V)) + 2;
    vector<int> bag;
    for (int i = 0; i <= top; i++) {
        bag.push_back((int) (pow(V, i)));
        bag.push_back((int) (pow(V, i)));
    }
    bool ans = isTrade(bag, W);
    if (ans) {
        return "YES";
    }
    return "NO";
}

int main() {
    // Add your test cases here
    std::cout << (solution(10, 9) == "YES") << std::endl;
    std::cout << (solution(200, 40199) == "YES") << std::endl;
    std::cout << (solution(108, 50) == "NO") << std::endl;
    return 0;
}
