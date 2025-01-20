#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//豆包, 101 兔群繁殖之谜
long long solution(int A) {
    // Edit your code here
    ll adult = 0;
    ll child = 1;
    for (int i = 1; i <= A; i++) {
        ll new_born = adult;
        adult += child;
        child = new_born;
    }

    // cout << "res = " << adult + child << "\n";
    return adult + child;
}

int main() {
    // Add your test cases here
    std::cout << (solution(1) == 1) << std::endl;
    std::cout << (solution(5) == 8) << std::endl;
    std::cout << (solution(15) == 987) << std::endl;

    return 0;
}
