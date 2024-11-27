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
     * 链表内指定区间反转
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write code here
        if (m == n) {
            return head;
        }
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        int count = 0;
        ListNode *cur = newHead;
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while (count <= n + 1) {
            if (count == m - 1) {
                pre = cur;
            }
            if (count == n + 1) {
                next = cur;
            }
            count++;
            if (cur != nullptr) {
                cur = cur->next;
            }
        }
        //反转开始位置往后有n - m个指向需要改变
        vector<ListNode *> res = reverse(pre->next, n - m);
        pre->next = res[1];
        res[0]->next = next;
        return newHead->next;
    }

    vector<ListNode *> reverse(ListNode *p, int len) {
        ListNode *first = p;
        ListNode *next = p->next;
        while (len > 0) {
            ListNode *temp = nullptr;
            if (next != nullptr) {
                temp = next->next;
                next->next = p;
                p = next;
                next = temp;
            }
            len--;
        }
        ListNode *last = p;
        return {first, last};
    }

    ListNode *getList(vector<int> &array) {
        ListNode *head = new ListNode(10);
        ListNode *cur = head;
        for (const auto &item: array) {
            cur->next = new ListNode(item);
            cur = cur->next;
        }
        return head->next;
    }

    void print(ListNode *head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << " ";
    }
};

int main() {
    //不是引用所以head指针进入其他函数是新的变量
    vector<int> array = {1, 2, 3, 4, 5, 6, 7};
    Solution solution;
    ListNode *head = solution.getList(array);
    head = solution.reverseBetween(head, 1, 1);
    solution.print(head);
    return 0;
}
