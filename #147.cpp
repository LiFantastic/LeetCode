/*============================================================
Problem: Insertion Sort List
==============================================================
Sort a linked list using insertion sort.
============================================================*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *pre, *cur=head, *dummyHead = new ListNode(0);
        while (cur) {
            ListNode *next = cur->next;
            pre = dummyHead;
            while (pre->next!=NULL && pre->next->val<cur->val)
                pre=pre->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
 
};