/*============================================================
Problem: Rotate List
==============================================================
Given a list, rotate the list to the right by k places, 
where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head==NULL) return NULL;
        ListNode *p=head;
        int n=1;
        while (p->next) {
            p = p->next;
            n++;
        }
        k %= n;
        p->next=head;  // form a cycle
        p = head;
        for (int i=0; i<n-k-1; i++)
            p = p->next;
        head = p->next;  // record the new head
        p->next = NULL;  // break the cycle	
        return head;
    }
};