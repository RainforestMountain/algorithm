#include <bits/stdc++.h>
#include <vector>

using namespace std;

//dp[i][j] 在第i个加油站, 油量是j, 到达景区x的最小旅游花费
int dynamical(int i, int gas, vector<vector<int>> &gas_stations, vector<vector<int>> &dp) {
    int n = gas_stations.size();
    if (i >= n) {
        if (gas >= 200) return 0;
        return -1;
    }
    if (dp[i][gas] != -2) {
        return dp[i][gas];
    }
    //当前加不加油, 加多少, 并且当前油量到下一站需要消耗
    int ans = 0x3f3f3f3f;
    if (i < n - 1) {
        for (int g = 0; gas + g <= 400; g++) {
            int det = gas_stations[i + 1][0] - gas_stations[i][0];
            int tmp = 0;
            if (gas + g - det >= 0) {
                tmp = dynamical(i + 1, gas + g - det, gas_stations, dp);
                if (tmp != -1) {
                    ans = min(ans, tmp + g * gas_stations[i][1]);//加上加油的消费
                }
            }
        }
    } else {
        if (gas >= 0) {
            int tp = dynamical(i + 1, gas, gas_stations, dp);
            if (tp != -1) {
                ans = min(ans, tp);
            }
        }

    }
    if (ans == 0x3f3f3f3f) {
        dp[i][gas] = -1;
        return -1;
    } else {
        dp[i][gas] = ans;
        return ans;
    }
}

int solution(int distance, int n, std::vector<std::vector<int>> gas_stations) {
    // Please write your code here
    vector<vector<int>> new_gas;
    for (int i = 0; i < gas_stations.size(); i++) {
        if (gas_stations[i][0] < distance) {
            new_gas.push_back(vector<int>(gas_stations[i]));
        }
    }
    new_gas.push_back({distance, 0});
    n = new_gas.size();
    sort(new_gas.begin(), new_gas.end(), [](auto o1, auto o2) {
        return o1[0] < o2[0];
    });
    vector<vector<int>> dp(n + 1, vector<int>(401, -2));
    if (200 - new_gas[0][0] < 0) {
        return -1;
    }
    int ans = dynamical(0, 200 - new_gas[0][0], new_gas, dp);
    //cout << "ans = " << ans << "\n";
    return ans;
}

int main() {
    std::vector<std::vector<int>> gasStations1 = {
            {100, 1},
            {200, 30},
            {400, 40},
            {300, 20}};
    std::vector<std::vector<int>> gasStations2 = {
            {100, 999},
            {150, 888},
            {200, 777},
            {300, 999},
            {400, 1009},
            {450, 1019},
            {500, 1399}};
    std::vector<std::vector<int>> gasStations3 = {{101},
                                                  {100, 100},
                                                  {102, 1}};
    std::vector<std::vector<int>> gasStations4 = {
            {34,  1},
            {105, 9},
            {9,   10},
            {134, 66},
            {215, 90},
            {999, 1999},
            {49,  0},
            {10,  1999},
            {200, 2},
            {300, 500},
            {12,  34},
            {1,   23},
            {46,  20},
            {80,  12},
            {1,   1999},
            {90,  33},
            {101, 23},
            {34,  88},
            {103, 0},
            {1,   1}};

    std::cout << (solution(500, 4, gasStations1) == 4300) << std::endl;
    std::cout << (solution(500, 7, gasStations2) == 410700) << std::endl;
    std::cout << (solution(500, 3, gasStations3) == -1) << std::endl;
    std::cout << (solution(100, 20, gasStations4) == 0) << std::endl;
    std::cout << (solution(100, 0, std::vector<std::vector<int>>{}) ==
                  -1)
              << std::endl;

    return 0;
}