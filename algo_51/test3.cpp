#include <bits/stdc++.h>

using namespace std;

int solution(int N, std::vector<int> data_array) {
    // Please write your code here
    int n = N;
    //连续子数组翻转等价于 把左边[0..i]的连续子数组的和和右边连续子数组[n, i+ 1]的和加起来, 把右边连续子数组翻转过来就行
    data_array.insert(data_array.begin(), 0);
    vector<int> left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) {//以i结尾的最大连续子数组和 

    }
}

int main() {
    // You can add more test cases here
    std::vector<int> array1 = {
            1, 2, 3, -1, 4
    };
    std::vector<int> array2 = {
            -85, -11, 92, 6, 49, -76, 28, -16, 3, -29, 26, 37, 86, 3, 25,
            -43, -36, -27, 45, 87, 91, 58, -15, 91, 5, 99, 40, 68, 54, -95,
            66, 49, 74, 9, 24, -84, 12, -23, -92, -47, 5, 91, -79, 94, 61,
            -54, -71, -36, 31, 97, 64, -14, -16, 48, -79, -70, 54, -94, 48, 37,
            47, -58, 6, 62, 19, 8, 32, 65, -81, -27, 14, -18, -34, -64, -97,
            -21, -76, 51, 0, -79, -22, -78, -95, -90, 4, 82, -79, -85, -64, -79,
            63, 49, 21, 97, 47, 16, 61, -46, 54, 44};
    vector<int> array3 = {-5, -9, 6, 7, -6, 2};
    //std::cout << (solution(5, array1) == 10) << std::endl;
    std::cout << (solution(100, array2) == 1348) << std::endl;
    //std::cout << (solution(6, array3) == 15) << std::endl;
    return 0;
}