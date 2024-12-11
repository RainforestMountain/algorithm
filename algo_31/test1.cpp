#include <iostream>
#include <bits/stdc++.h>

using namespace std;

static int mod = 1000000007;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */

    //树状次数数组,统计一个元素val左边有几个比val大
    struct treeArray {
        vector<int> array;
        map<int, int> index;//1<-a1, 2<-a2
        vector<int> ls;

        explicit treeArray(int n, vector<int> &nums) {//n是去重后的数据
            array = vector<int>(n + 1, 0);
            index = map<int, int>();
            ls = vector<int>(nums);
            ls.insert(ls.begin(), -1);
            sort(ls.begin(), ls.end());
            for (int i = 1; i <= n; i++) {
                index[ls[i]] = i;
            }
        }

        int lowbit(int i) {
            return i & (-i);
        }

        //val对应离散化的数组下标i的次数加一 这个离散化数组是有序的,树状数组统计次数, 下标获取用map,
        void update(int val, int v) {
            int i = index[val];
            while (i < array.size()) {
                array[i] += v;
                i = i + lowbit(i);
            }
        }

        //左边大于val元素的出现的次数
        int getCount(int val) {
            int i = index[val];
            int sum1 = 0;
            int n = array.size() - 1;//最后一个位置求前缀和
            while (n > 0) {
                sum1 = (sum1 + array[n]) % mod;
                n = n - lowbit(n);
            }
            int sum2 = 0;
            while (i > 0) {//i位置求前缀和
                sum2 = (sum2 + array[i]) % mod;
                i = i - lowbit(i);
            }
            return (sum1 - sum2) % mod;
        }

    };

    int InversePairs(vector<int> &nums) {
        // write code here
        int n = nums.size();
        treeArray tree = treeArray(n, nums);
        int res = 0;
        for (const auto &val: nums) {
            res = (res + tree.getCount(val)) % mod;
            tree.update(val, 1);
        }
        return res;

    }
};

int main() {

    Solution solution;
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 0};
    cout << solution.InversePairs(array) << "\n";
    return 0;
}
