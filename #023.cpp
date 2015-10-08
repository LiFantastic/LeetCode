/*============================================================
Problem: Merge k Sorted Lists
==============================================================
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.
============================================================*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Node {
	ListNode* listNode;
	
	Node(ListNode* n) {
		listNode = n;
	}
	bool operator<(const Node& other) const {
		if (listNode==NULL)
			return false;
		else if (other.listNode==NULL)
			return true;
		else
			return listNode->val < other.listNode->val;
	}
	bool operator>(const Node& other) const {
		if (other.listNode==NULL)
			return false;
		else if (listNode==NULL)
			return true;
		else
			return listNode->val > other.listNode->val;
	}
};
    
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) {
    	if (lists.empty()) return NULL;
		int n = lists.size();
		vector<Node> heap;
		heap.reserve(n);
		for (int i=0; i<n; i++)
			heap.push_back(Node(lists[i]));
		make_heap(heap.begin(), heap.end(), greater<Node>());
		ListNode *dummyHead= new ListNode(0), *p = dummyHead;
		pop_heap(heap.begin(), heap.end(), greater<Node>());
		Node smallest = heap.back();
		heap.pop_back();
		while (smallest.listNode) {
			ListNode *next = smallest.listNode->next;
			p->next = smallest.listNode;
			smallest.listNode->next = NULL;
			p = p->next;

			heap.push_back(Node(next));
			push_heap(heap.begin(), heap.end(), greater<Node>());
			pop_heap(heap.begin(), heap.end(), greater<Node>());
			smallest = heap.back();
			heap.pop_back();
		}
		p = dummyHead->next;
		delete dummyHead;
		return p;    
	}
};