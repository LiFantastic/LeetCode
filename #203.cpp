/*============================================================
Problem: Remove Linked List Elements
==============================================================
Remove all elements from a linked list of integers that have 
value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(0), *p=dummyHead, *tmp;
        dummyHead->next = head;

        while (p->next) {
            if (p->next->val == val) {
                tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }
            else
                p = p->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
	}
};