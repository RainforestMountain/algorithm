#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int x = 0;
        for (int i = 0; i < sentence.size(); i++) {
            int pos = sentence[i] - 'a';
            if (((x >> pos) & 1) == 0) {
                x = x ^ (1 << pos);
            }
        }
        //第i位  用与 (x >> pos) & 1,
        // 修改     用异或 0 ^ 0 = 0, 1 ^ 1 = 0, 1 ^ 0 = 1, 0 ^ 1 = 1
        //       x ^ (1 << pos)
        //       0011
        //       0100
        //       0111
        cout << x << "\n";
        return x == 67108863;
    }
};

int main() {
    Solution solution;
    cout << 0b00000011111111111111111111111111 << "\n";
    cout << solution.checkIfPangram("thequickbrownfoxjumpsoverthelazydog");
    cout << 25 * 13 << "\n";
    return 0;
}
