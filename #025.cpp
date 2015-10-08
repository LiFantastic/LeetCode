/*============================================================
Problem: Reverse Nodes in k-Group
==============================================================
Given a linked list, reverse the nodes of a linked list k at 
a time and return its modified list.
If the number of nodes is not a multiple of k then left-out 
nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself 
may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
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
private:
    void reverse(ListNode* pPre, ListNode* pFirst, ListNode* pKth) {
	    ListNode *p = pFirst;
 	    while (p!=pKth) { // (p) - (pTmp) - ... - (pKth) - 
		    ListNode* pTmp = p->next;
		    p->next = pKth->next;
		    pKth->next = p;
		    p = pTmp;
	    }
	    pPre->next=pKth;
    }
public:
    ListNode* reverseKGroup(ListNode* head ,int k) {
	    if (!head||!head->next||k<=1)
		    return head;

	    ListNode *pFirst=head, *pKth=pFirst, *dummyHead=new ListNode(0), *pPre=dummyHead;
	    dummyHead->next = head;

	    while (true) {
		    int cnt=k-1;
		    while (cnt && pKth) {
			    pKth = pKth->next;
			    cnt--;
		    }
		    if (cnt>0 || pKth==NULL)
			    break;

		    reverse(pPre, pFirst, pKth);
		   	
		    pPre   = pFirst;
		    pFirst = pPre->next;
		    pKth   = pFirst;
	    }
	    pFirst = dummyHead->next;
	    delete dummyHead;
	    return pFirst;
    }
};