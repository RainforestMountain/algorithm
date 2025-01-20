#include <iostream>
#include <vector>
#include <map>

std::map<long long, long long> counts;

void MergeSort(std::vector<long long>& arr, long long left, long long right) {
    if (left == right) {
        return;
    }
    long long mid = (left + right) >> 1;
    MergeSort(arr, left, mid);    // 分治左
    MergeSort(arr, mid + 1, right); // 分治右
    std::vector<long long> tmp(right - left + 1);
    long long k = 0, p = left, q = mid + 1;
    for (; p <= mid && q <= right; ) {
        if (arr[p] > arr[q]) {
            counts[arr[q]] += mid + 1 - p; // 因为右部分的交换次数已经记录了, 所以只考虑左边的交换次数, 交换到p位置
            tmp[k++] = arr[q++];
        } else {
            counts[arr[p]] += q - (mid + 1); // 因为左部分的交换次数已经记录了, 所以只考虑右边的交换次数, 交换到q位置
            tmp[k++] = arr[p++];
        }
    }
    for (; q <= right; ) {
        tmp[k++] = arr[q++];
    }
    for (; p <= mid; ) {
        counts[arr[p]] += right - mid; // 需要交换到最右边去, 下标的计算
        tmp[k++] = arr[p++];
    }
    for (long long i = 0; i < tmp.size(); ++i) {
        arr[left + i] = tmp[i];
    }
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> arr(n + 1);
    for (long long i = 1; i <= n; i++) {
        std::cin >> arr[i];
    }
    MergeSort(arr, 1, n);
    long long sum = 0;
    for (const auto& pair : counts) {
        sum += pair.second * (pair.second + 1) / 2;
    }
    std::cout << sum << std::endl;
    return 0;
}