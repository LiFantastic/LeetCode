/*============================================================
Problem: Remove Duplicates from Sorted List
==============================================================
Given a sorted linked list, delete all duplicates such that 
each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head, *succeed;
        
        while (cur!=NULL) {
            succeed = cur->next;
            while (succeed!=NULL && succeed->val==cur->val) {
                succeed = succeed->next;
                delete cur->next;
                cur->next = succeed;
            }
			cur = cur->next;
        }
        return head;
    }
};