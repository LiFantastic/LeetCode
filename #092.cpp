/*============================================================
Problem: Reverse Linked List II
==============================================================
Reverse a linked list from position m to n. Do it in-place and 
in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
============================================================*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL) return NULL;
        ListNode *frontTail = NULL;  // frontTail -> m(start to reverse)  -> n(end of reverse)  -> 
        ListNode *cur = head;
        for(int i=0; i<m-1; i++) {
            frontTail = cur;
            cur = cur->next;
        }  // now, cur is the first node to reverse
        ListNode *reversedTail = cur;  // after reverse, cur should be the tail of the reversed part
        ListNode *pre = cur;
        cur = cur->next;
        for (int i=m; i<n; i++) {
            ListNode *succeed = cur->next;
            cur->next = pre;  // reverse
            pre = cur;
            cur = succeed;
        }  // now pre should be the head of the reversed part, cur is the first node of the remain part
        reversedTail->next = cur;  // link the reversedTail to cur
        if (frontTail)
            frontTail->next = pre;
        else
            head = pre;
        return head;
    }
};