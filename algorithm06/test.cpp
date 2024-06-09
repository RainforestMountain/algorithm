#include <iostream>
#include <vector>
#include <algorithm>

double knapsack(std::vector<double> p, std::vector<double> w, double m) {
    std::vector<std::pair<int, double>> unitValue;
    for (int i = 0; i < p.size(); i++) {
        unitValue.push_back(std::make_pair(i, p[i] / w[i]));
    }
    std::sort(unitValue.begin(), unitValue.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    double value = 0;
    for (int i = 0; i < unitValue.size() && m > 0; i++) {
        if (w[unitValue[i].first] < m) {
            m -= w[unitValue[i].first];
            value += p[unitValue[i].first];
        } else {
            value += m / w[unitValue[i].first] * p[unitValue[i].first];
            m = 0;
        }
    }
    return value;
}

int main() {
    std::vector<double> p = {18, 12, 4, 1};
    std::vector<double> w = {12, 10, 8, 3};
    double m = 25;
    std::cout << knapsack(p, w, m) << std::endl;
    return 0;
}
