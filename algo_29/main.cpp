#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead1 ListNode类
     * @param pHead2 ListNode类
     * @return ListNode类
     */
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        // write code here
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->val <= pHead2->val) {
                cur->next = pHead1;
                cur = cur->next;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                cur = cur->next;
                pHead2 = pHead2->next;
            }
        }
        while (pHead1 != nullptr) {
            cur->next = pHead1;
            cur = cur->next;
            pHead1 = pHead1->next;
        }
        while (pHead2 != nullptr) {
            cur->next = pHead2;
            cur = cur->next;
            pHead2 = pHead2->next;
        }
        return res->next;
    }

    static ListNode *getList(vector<int> &array) {
        ListNode *head = new ListNode(10);
        ListNode *cur = head;
        for (const auto &item: array) {
            cur->next = new ListNode(item);
            cur = cur->next;
        }
        return head->next;
    }

    static void print(ListNode *head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << " ";
    }
};

int main() {

    return 0;
}
