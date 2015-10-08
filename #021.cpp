/*============================================================
Problem: Merge Two Sorted Lists
==============================================================
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of 
the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *res, *p=dummyHead, *p1=l1, *p2=l2;
        
        while (p1&&p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};