package test2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        //两两一组
        //归并排序
        List<ListNode> nlist = new ArrayList<>();
        nlist.addAll(Arrays.asList(lists));
        mergeSort(lists, 0, nlist.size() - 1, true);
        return lists[0];
    }

    /**
     * 归并排序
     * 去向下展开分治，直到是0个或者1个或者2个， 然后开始向上合并
     *
     * @param lists
     * @param left
     * @param right
     * @param tag true是左， false是右
     */
    private void mergeSort(ListNode[] lists, int left, int right, boolean tag) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) >> 1;
        mergeSort(lists, left, mid, true);
        mergeSort(lists, mid + 1, right, false);
        ListNode tmp = merge(lists[left], lists[right]);
        if (tag) {
            lists[left] = tmp;
            lists[right] = tmp;
        } else {
            lists[left] = tmp;
            lists[right] = tmp;
        }
    }

    private ListNode merge(ListNode h1, ListNode h2) {
        ListNode res = new ListNode(-1);
        ListNode curK = res;
        ListNode cur1 = h1;
        ListNode cur2 = h2;
        while (cur1 != null && cur2 != null) {
            int v1 = cur1.val;
            int v2 = cur2.val;
            if (v1 >= v2) {
                curK.next = cur2;
                curK = curK.next;
                cur2 = cur2.next;
            } else {
                curK.next = cur1;
                curK = curK.next;
                cur1 = cur1.next;
            }
        }
        while (cur1 != null) {
            curK.next = cur1;
            curK = curK.next;
            cur1 = cur1.next;
        }
        while (cur2 != null) {
            curK.next = cur2;
            curK = curK.next;
            cur2 = cur2.next;
        }
        curK.next = null;
        return res.next;
    }

    public static void main(String[] args) {
        ListNode h1 = new ListNode(1);
        h1.next = new ListNode(4);
        h1.next.next = new ListNode(5);
        ListNode h2 = new ListNode(1);
        h2.next = new ListNode(3);
        h2.next.next = new ListNode(4);

        ListNode h3 = new ListNode(2);
        h3.next = new ListNode(6);

        Solution solution = new Solution();
        ListNode[] lists = {h1, h2, h3};
        ListNode cur = solution.mergeKLists(lists);
        while (cur != null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }

    }
}
