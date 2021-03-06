/*============================================================
Problem: Intersection of Two Linked Lists
==============================================================
Write a program to find the node at which the intersection of 
two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* iter1 = headA;
        ListNode* iter2 = headB;
        int len1 = 1;
        while (iter1->next != NULL) {
            iter1 = iter1->next;
            len1 ++;
        }
        int len2 = 1;
        while(iter2->next != NULL) {
            iter2 = iter2->next;
            len2 ++;
        }
        if(iter1 != iter2) return NULL;  // different tails
        iter1 = headA;
        iter2 = headB;
        if (len1 > len2) {
            for (int i=0; i<len1-len2; i++)
                iter1 = iter1->next;
        }
        else if (len2 > len1) {
            for (int i=0; i<len2-len1; i++)
                iter2 = iter2->next;
        }
        while (iter1 != iter2) {
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        return iter1;
    }
};