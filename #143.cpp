/*============================================================
Problem: Reorder List
==============================================================
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        // find the middle node: O(n)
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        // cut from the middle and reverse the second half: O(n)
        ListNode *head2 = p1->next;
        p1->next = NULL;
    
        // reverse list2, starting from head2
        p1 = head2;
        p2 = p1->next;
        p1->next = NULL;
        while (p2) {
            auto p2Next = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2Next;
        }
        head2 = p1;
        
        // merge two lists: O(n)
        for (p1 = head, p2 = head2; p1&&p2; ) {
            auto p1Next = p1->next;
            auto p2Next = p2->next;
            p1->next = p2;
            p2->next = p1Next;
            p1 = p1Next;
            p2 = p2Next;
        }
	}
};