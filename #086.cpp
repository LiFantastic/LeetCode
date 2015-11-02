/*============================================================
Problem: Partition List
==============================================================
Given a linked list and a value x, partition it such that all 
nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes 
in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return head;
        ListNode *lessHead = new ListNode(0), *lessTail = lessHead;
        ListNode *geqHead = new ListNode(0), *geqTail = geqHead;
        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                lessTail->next = cur;
                lessTail = cur;
                cur = cur->next;
                lessTail->next = NULL;
            }
            else {
                geqTail->next = cur;
                geqTail = cur;
                cur = cur->next;
                geqTail->next = NULL;
            }
        }
        lessTail->next = geqHead->next;
        cur = lessHead->next;
        delete lessHead;
        delete geqHead;
        return cur;
    }
};