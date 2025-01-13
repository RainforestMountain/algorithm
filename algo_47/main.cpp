#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbling_sort(vector<int> &array) {
    //将大的移动后面
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}

int main() {
    time_t start = time(nullptr);
    srand(static_cast<unsigned int>(time(nullptr)));
//    mt19937 generator(rand());
//    uniform_int_distribution<int> distribution(0, 10000000);
    vector<int> array(50000);
    for (int i = 0; i < array.size(); i++) {
        array[i] = rand() % 10000000 + 1;
    }
    bubbling_sort(array);
    time_t end = time(nullptr);
    cout << end - start << "ms\n";
    return 0;
}
