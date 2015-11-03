/*============================================================
Problem: Linked List Cycle II
==============================================================
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
============================================================*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL) return false;
            
        ListNode *slow = head, *fast = head;
        bool isCycle =false;
        
        while (fast!=NULL) {
            if (!fast->next || !fast->next->next) {
                isCycle = false;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast==slow) {
                isCycle = true;
                break;
            }
        }
        if (!isCycle) return NULL;
        slow = head;
        while (slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};