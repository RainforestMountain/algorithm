#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 200000 + 4;

struct st {
public:
    int age;

    st() {

    }

    st(int age) {
        this->age = age;
    }

    bool operator<(const st &o) const {
        return age < o.age;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<st> students(3);
    students[0] = st(15);
    students[1] = st(25);
    students[2] = st(20);
    sort(students.begin(), students.end());
    for (const auto &item: students) {
        cout << item.age << "\n";
    }
    return 0;
}
