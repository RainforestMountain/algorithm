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
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write code here
        if (head == nullptr) {
            return nullptr;
        }
        //滑动窗口
        ListNode *left = head;
        ListNode *right = head;

        for (; right != nullptr && left != nullptr; right = right->next) {
            if (right->val != left->val) {
                left->next = right;
                left = right;
            }
        }
        if (right == nullptr && left != nullptr) {
            left->next = right;
        }
        return head;
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

    void print(ListNode *head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "\n";
    }
};

int main() {
    Solution solution;
    vector<int> array = {1};
    auto list = solution.getList(array);
    solution.print(list);
    list = solution.deleteDuplicates(list);
    solution.print(list);

//    vector<int, allocator<int>> v;
//    priority_queue<> q;
//    map<> m;
//    queue<> q;


    return 0;
}
