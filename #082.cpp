/*============================================================
Problem: Remove Duplicates from Sorted List II
==============================================================
Given a sorted linked list, delete all nodes that have duplicate 
numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        ListNode *res, *tmp, *dummyHead, *pre, *cur = head, *succeed;  // pre -> cur -> succeed
        
        dummyHead = new ListNode(0);
        pre = dummyHead;
        pre->next = head;
        res = pre;
        
        while (cur!=NULL) {
            succeed = cur->next;
            if (succeed!=NULL && succeed->val==cur->val) {
                while (succeed!=NULL && succeed->val==cur->val) {
                    succeed = succeed->next;
                    delete cur->next;  // real deletion with this
                    cur->next = succeed;
                }
                delete cur;
                pre->next = succeed;
                cur = succeed;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        delete dummyHead;
        return res->next;
    }
};