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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode *sortInList(ListNode *head) {
        // write code here
        if (head == nullptr) {
            return nullptr;
        }
        vector<ListNode *> v;
        ListNode *cur = head;
        while (cur != nullptr) {
            v.push_back(cur);
            cur = cur->next;
        }

        sort(v.begin(), v.end(), [](ListNode *a, ListNode *b) {
            return a->val < b->val;
        });
        ListNode *newHead = new ListNode(-1);
        cur = newHead;

        for (const auto &node: v) {
            cur->next = node;
            cur = node;
        }
        cur->next = nullptr;
        return newHead->next;
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


    ListNode *sortInList2(ListNode *head) {
        // write code here
        if (head == nullptr) {
            return nullptr;
        }
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        ListNode *cur = head;
        while (cur != nullptr) {
            q.push(cur);
            cur = cur->next;
        }

        ListNode *res = new ListNode(-1);
        cur = res;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
        }
        cur->next = nullptr;
        return res->next;


    }

    struct compare {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val < b->val;
        }
    };

};

int main() {

    return 0;
}
