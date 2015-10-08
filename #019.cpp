/*============================================================
Problem: Remove Nth Node From End of List
==============================================================
Given a linked list, remove the nth node from the end of list 
and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list 
becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;
            
        ListNode *pPre = NULL;
        ListNode *p = head;
        ListNode *q = head;
        
        for(int i=0; i<n-1; i++)
            q = q->next;  // q is n-1 step ahead of p
            
        while (q->next) {
            pPre = p;
            p = p->next;
            q = q->next;
        }  // now p is the node to delete  
        
        if (pPre == NULL) { // when n = totalLen - 1, pPre will be NULL, p will be head, delete head
            head = p->next;
            delete p;
        }
        else {
            pPre->next = p->next;
            delete p;
        }
        return head;
    }
};