#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        // 边缘, buildings[i][0] ,buildings[i][1]
        // 包含边缘的建筑有   left <= x < right
        // 边遍历, 边加入优先级队列, 主要考虑包含当前横坐标的建筑,每个建筑最多添加一次,用一个变量记录
        //符合条件的还应该满足横坐标的在建筑对应的纵坐标值刚好就是最高的纵坐标,并且唯一
        //无效的点,是指横坐标的在建筑对应的纵坐标值小于等于最高的纵坐标, 如果等于那么不唯一,
        // 最高的纵坐标在上一个关键点一定用过了, 因为这个最高纵坐标形成的平行线是离当前横坐标最近的
        priority_queue<vector<int>, vector<vector<int>>, Compare> q;
        vector<int> boundaries;

        for (const auto &building: buildings) {
            boundaries.push_back(building[0]);
            boundaries.push_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());
        sort(buildings.begin(), buildings.end(), [](auto o1, auto o2) {
            return o1[0] < o2[0];
        });
        vector<vector<int>> result;
        //开始遍历
        int i = 0, j = 0;
        for (; i < boundaries.size(); i++) {
            int x = boundaries[i];
            for (; j < buildings.size(); j++) {
                if (buildings[j][0] <= x && x < buildings[j][1]) {
                    q.push(buildings[j]);
                } else {
                    break;
                }
            }
            //找到包含当前边缘x的建筑, 因为之前加了,没有全删
            while (!q.empty()) {
                auto high = q.top();
                if (high[0] <= x && x < high[1]) {
                    if (!result.empty() && result[result.size() - 1][1] == high[2]);//无效
                    else {
                        result.push_back({x, high[2]});//符合条件的可以直接跳出,不用弹出,可能之后要用到
                    }
                    break;
                }
                q.pop();//右边缘小的一定没用了, 左边缘不可能大,因为加入的时候有限制,buildings左边缘还排序了, 感觉不如暴力
            }
            if (q.empty()) {//队列为空, 说明没有建筑包含, 那么说明纵坐标是0
                if (result[result.size() - 1][1] != 0) result.push_back({x, 0});
            }
        }
        return result;

    }

    struct Compare {
        bool operator()(vector<int> &o1, vector<int> &o2) const {
            return o1[2] < o2[2];
        }
    };
};

int main() {
    Solution solution;
    vector<vector<int>> buildings = {{2,  9,  10},
                                     {3,  7,  15},
                                     {5,  12, 12},
                                     {15, 20, 10},
                                     {19, 24, 8}};
    auto res = solution.getSkyline(buildings);
    for (const auto &item: res) {
        cout << item[0] << " , " << item[1] << "\n";
    }
    return 0;
}
