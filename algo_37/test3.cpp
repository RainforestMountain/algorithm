#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> stu(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> stu[i];
    }
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + stu[i];
    }
    //ö��������, �õ�����ĺ� sumL, Ȼ����treeset��ȡ��ӽ�sumL��������������, Ҫ��ǰʹ��treeset����Ҫ��, �����Ƽ�ö����������Ҷϵ�
    //����������ǰ׺��

    multiset<ll> rSum;//�����ظ�Ԫ��
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rSum.insert(pre[j] - pre[i - 1]);
        }
    }
    //l1 <= r1 < l2 <= r2
    ll ans = LONG_LONG_MAX;
    for (int r1 = 1; r1 <= n - 1; r1++) {
        //ɾ����r1Ϊ��˵��������, ɾ����
        for (int r2 = r1; r2 <= n; r2++) {
            ll sum = pre[r2] - pre[r1 - 1];
            if (rSum.find(sum) != rSum.end()) {
                rSum.erase(rSum.find(sum));
            }
        }
        for (int l1 = 1; l1 <= r1; l1++) {
            ll sum = pre[r1] - pre[l1 - 1];
            if (rSum.lower_bound(sum) != rSum.end()) { //���ص�һ�����ڵ���sum��Ԫ��
                ans = min(ans, abs(*rSum.lower_bound(sum) - sum));
                if (rSum.lower_bound(sum) != rSum.begin()) {
                    //ֻҪlower_bound(k) != s.begin(), ����һ��Ԫ��ָ��λ��, ��ô�����ҵ�С�ڵ���k��Ԫ��
                    ans = min(ans, abs(*(--rSum.lower_bound(sum)) - sum));
                }
            }
        }
    }
    cout << ans << "\n";

}

int main() {

    solve();
//    multiset<int> s = {1, 2, 3, 5, 6};
//    cout << *(--s.lower_bound(0)) << "\n";//С�ڵ���
//    cout << *s.lower_bound(4) << "\n";//���ڵ���
    return 0;
}

