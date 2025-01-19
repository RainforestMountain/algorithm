#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const pair<int, int> &o1, const pair<int, int> &o2) const {
        return o1.second > o2.second; // 孩子节点大于父节点
    }
};

std::string solution(std::vector<int> nums, int k) {
    // Please write your code here
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }
    //top-k
    //需要我们不断提高下限, 所有堆顶元素是下限, 小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    for (const pair<int, int> &kv: mp) {
        if (q.size() < k) {
            q.push(kv);
            continue;
        }
        if (kv.second > q.top().second) {
            q.pop();
            q.push(kv);
        }
    }
    string ans;
    vector<int> path;
    while (!q.empty()) {
        path.push_back(q.top().first);
        q.pop();
    }
    sort(path.begin(), path.end());
    for (const auto &item: path) {
        ans.insert(ans.size(), to_string(item));
        ans.insert(ans.size(), ",");
    }
    ans.erase(ans.size() - 1);
//    cout << "ans = " << ans << "\n";
    return ans;
}

int main() {
    //  You can add more test cases here
    std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    std::vector<int> nums2 = {1};

    std::cout << (solution(nums1, 2) == "1,2") << std::endl;
    std::cout << (solution(nums2, 1) == "1") << std::endl;

    return 0;
}