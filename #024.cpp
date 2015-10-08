/*============================================================
Problem: Swap Nodes in Pairs
==============================================================
Given a linked list, swap every two adjacent nodes and return 
its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not 
modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *dummyHead=new ListNode(0), *cur=dummyHead, *p=head;
        while (p && p->next) { // (cur) - [(p) - (p->next)] - (next) and [is the elements to swap]
            ListNode *next = p->next->next;
            cur->next = p->next;
            p->next->next = p;
            p->next = next;
            cur = p;
            p = next;
        }
        if (p) cur->next = p;
        p = dummyHead->next;
        delete dummyHead;
        return p;
    }
};