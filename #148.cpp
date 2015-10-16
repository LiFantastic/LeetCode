/*============================================================
Problem: Sort List
==============================================================
Sort a linked list in O(n log n) time using constant space 
complexity.
============================================================*/
/**
 * Definition for singly-linked list.
 * struct ListNode {Sort a linked list in O(n log n) time using constant space complexity.
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //use the fast and slow pointer to get the middle of a ListNode
     ListNode* getMiddleOfList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        return slow;
    }
    
    //merge the two sorted list
    ListNode* mergeList(ListNode* a, ListNode* b) {
    	ListNode* dummyHead = new ListNode(-1);
    	ListNode* cur = dummyHead;
    	while (a && b) {
    		if (a->val<=b->val) {
    			cur->next = a; 
    			a = a->next;
    		} 
    		else {
    			cur->next = b;
    			b = b->next;
    		}
    		cur = cur->next;
    	}
    	cur->next = a ? a : b;
    	cur = dummyHead->next;
    	delete dummyHead;
    	return cur;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;
    	ListNode* middle = getMiddleOfList(head);
    	ListNode* head2 = middle->next;  // split from middle
    	middle->next = NULL;
    	return mergeList(sortList(head), sortList(head2));
    }
};