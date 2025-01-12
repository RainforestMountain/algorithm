

#include <bits/stdc++.h>

using namespace std;
const int N = 100002;
int loca[26];//第一次出现的位置, 对于没有出现在s的字符, 默认用它后面有的字符位置表示, 来方便插入, 这个也要不断更新
map<int, vector<char>> insert;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<char> s(n + 1);
    vector<char> t(m + 1);
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("%c", &s[i]);
    }
    getchar();
    for (int i = 1; i <= m; i++) {
        scanf("%c", &t[i]);
    }
    sort(t.begin() + 1, t.end());
    //类似归并,
    //双指针解法
    //减少返回比较次数,
    //对于t[j]大于s[i], 那么t[x]也会大于s[i] ,(x > j) , 因为t有序, 那么返回比较时间减少了,
    int i = 1;
    int j = 1;
    int k = 1;
    vector<char> res(n + m + 1);
    while (i <= n && j <= m) {
        if (s[i] > t[j]) { //相等的时候,不急着添加t[j]因为可能让字典序变大, 比如s[i]后面的s[i + 1] 比t[j]小,那么字典序就变大了
            // 只有当s[i] > t[j]的时候,才能真的确定可以降低字典序
            res[k] = t[j];
            j++;
            k++;
        } else {//s[i] <= t[j] , 让t[j]往后面找位置插入, 直到遇到一个大于它的或者是末尾
            res[k] = s[i];
            i++;
            k++;
        }
    }
    while (i <= n) {
        res[k] = s[i];
        i++;
        k++;
    }
    while (j <= m) {
        res[k] = t[j];
        j++;
        k++;
    }

    for (i = 1; i <= m + n; i++) {
        cout << res[i];
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}