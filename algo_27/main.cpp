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
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode *addInList(ListNode *head1, ListNode *head2) {
        // write code here
        int s = 0;//本位和
        int c = 0;//进位和
        ListNode *cur1 = reverse(head1);
        ListNode *cur2 = reverse(head2);
        ListNode *res = nullptr;//头插法
        while (cur1 != nullptr && cur2 != nullptr) {
            s = cur1->val + cur2->val + c;
            c = s / 10;
            s = s % 10;
            ListNode *tmp = new ListNode(s);
            tmp->next = res;
            res = tmp;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1 != nullptr) {
            s = cur1->val + c;
            c = s / 10;
            s = s % 10;
            ListNode *tmp = new ListNode(s);
            tmp->next = res;
            res = tmp;
            cur1 = cur1->next;
        }
        while (cur2 != nullptr) {
            s = cur2->val + c;
            c = s / 10;
            s = s % 10;
            ListNode *tmp = new ListNode(s);
            tmp->next = res;
            res = tmp;
            cur2 = cur2->next;
        }
        if (c != 0) {
            ListNode *tmp = new ListNode(c);
            tmp->next = res;
            res = tmp;
        }
        return res;
    }

    ListNode *reverse(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head->next = nullptr;
        return pre;
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
        cout << "\n";
    }

    ListNode *oddEvenList(ListNode *head) {
        // write code here
        //原地修改
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *eBegin = even;
        while (odd != nullptr && even != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            if (odd != nullptr) {
                even->next = odd->next;
            }
            even = even->next;
        }
        ListNode *cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = eBegin;
        return head;
    }

    bool isPail(ListNode *head) {
        if (head == nullptr) {
            return true;
        }
        stack<ListNode *> st;
        ListNode *cur = head;
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->next;
        }
        ListNode *left = head;
        while (true) {
            ListNode *right = st.top();
            if (left->val != st.top()->val) {
                return false;
            }
            if (left->next == right || left == right) {
                return true;
            }
            left = left->next;
            st.pop();
        }
    }
};

int main() {

    Solution solution;
//    vector<int> array1 = {9, 3, 7};
//    auto l1 = solution.getList(array1);
//    vector<int> array2 = {6, 3};
//    auto l2 = solution.getList(array2);
//    auto res = solution.addInList(l1, l2);
//    solution.print(res);

    vector<int> array = {1,2,3};
    auto l = solution.getList(array);
//    solution.print(l);
//    l = solution.oddEvenList(l);
//    solution.print(l);
    cout << solution.isPail(l) << "\n";
    return 0;
}
