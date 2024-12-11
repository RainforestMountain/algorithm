#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        //合并区间
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](auto o1, auto o2) {
            if (o1[0] < o2[0]) {
                return true;
            } else if (o1[0] > o2[0]) {
                return false;
            } else {
                return o1[1] < o2[1];
            }
        });
        //合并区间
        for (int i = 0; i < intervals.size() - 1; i++) {
            while (i < intervals.size() - 1 && intervals[i][1] >= intervals[i + 1][0]) {
                int left = min(intervals[i][0], intervals[i + 1][0]);
                int right = max(intervals[i][1], intervals[i + 1][1]);
                intervals.erase(intervals.begin() + i, intervals.begin() + i + 2);
                intervals.insert(intervals.begin() + i, {left, right});
            }
        }

        return intervals;
    }

    vector<vector<int>> insert2(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ans;
        for (const auto &interval: intervals) {
            if (interval[1] < newInterval[0]) {
                ans.push_back(interval);
                continue;
            }
            if (newInterval[1] < interval[0]) {
                ans.push_back(interval);
                continue;
            }
            newInterval[0] = min(interval[0], newInterval[0]);
            newInterval[1] = max(interval[1], newInterval[1]);
        }
        //找位置添加newInterval
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0 && newInterval[1] < ans[0][0]) {
                ans.insert(ans.begin(), newInterval);
                return ans;
            }
            if (i != ans.size() - 1 && ans[i][1] < newInterval[0] && newInterval[1] < ans[i + 1][0]) {
                ans.insert(ans.begin() + i + 1, newInterval);
                return ans;
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3},
                                     {7, 9}
    };
    vector<int> newInterval = {2, 5};
    auto res = solution.insert2(intervals, newInterval);
    for (const auto &item: res) {
        cout << item[0] << " " << item[1] << "\n";
    }
    cout << "\n";

    return 0;
}
