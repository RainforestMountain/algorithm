#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 100005;

struct Point {
    ll h;
    ll t;
} a[N], c[N];


void Merge(Point *a, int first, int end) { //归并排序
    int tmp = first, mid = (first + end) >> 1, p = first, q = mid + 1;
    while (p <= mid && q <= end)
        if (a[p].h > a[q].h) {
            a[q].t += mid + 1 - p; //记录答案
            c[tmp++] = a[q++];
        } else {
            a[p].t += q - 1 - mid; //记录答案
            c[tmp++] = a[p++];
        }
    while (q <= end) c[tmp++] = a[q++];
    q--;
    while (p <= mid) a[p].t += q - mid, c[tmp++] = a[p++];
    for (int i = first; i <= end; i++) a[i] = c[i];
}

void mergeSort(Point *a, int first, int end) {//分治主程序
    if (first == end) return;
    int mid = (first + end) >> 1;
    mergeSort(a, first, mid), mergeSort(a, mid + 1, end);
    Merge(a, first, end);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].h;
        a[i].t = 0;
    }
    mergeSort(a, 1, n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i].t * (a[i].t + 1) / 2;
    }
    cout << sum << "\n";
    return 0;
}