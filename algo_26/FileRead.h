

#ifndef ALGO_26_FILEREAD_H
#define ALGO_26_FILEREAD_H

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s = "abc";
int pos = 0;

int read4(char temp[4]) {
    int j = 0;
    for (; pos < s.size() && j < 4; pos++, j++) {
        temp[j] = s[pos];
    }

    return j;
}

#endif //ALGO_26_FILEREAD_H
