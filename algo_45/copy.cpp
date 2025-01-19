
#include <bits/stdc++.h>

using namespace std;


int main() {
    time_t start = time(nullptr);
    srand(static_cast<unsigned int>(time(nullptr)));
    mt19937 generator(rand());
    uniform_int_distribution<int> distribution(0, 500000);
    vector<int> array(500000);
    for (int i = 0; i < array.size(); i++) {
        array[i] = distribution(generator);
    }
    sort(array.begin(), array.end());
    time_t end = time(nullptr);
    cout << end - start << "ms\n";
    return 0;
}
