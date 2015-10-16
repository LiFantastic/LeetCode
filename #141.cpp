/*============================================================
Problem: Linked List Cycle
==============================================================
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if (head==NULL) return false;
            
        ListNode *slow = head, *fast = head->next;
        
        while (fast!=NULL) {
            if (fast->next == NULL) return false;
            if (fast->next->next==NULL) return false;
            if (fast==slow) return true;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};