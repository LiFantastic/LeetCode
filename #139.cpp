/*============================================================
Problem: Copy List with Random Pointer
==============================================================
A linked list is given such that each node contains an additional 
random pointer which could point to any node in the list or null.

Return a deep copy of the list.
============================================================*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *oriIter, *pseudoHead, *curIter, *next;
        
        oriIter = head;
        while (oriIter!=NULL) {
            next = oriIter->next;
            oriIter->next = new RandomListNode(oriIter->label);;
            oriIter->next->next = next;        
            oriIter = next;
        }  // origin1 -> copy1 -> origin2 -> copy2 -> ... ->
        
        oriIter = head;
        while (oriIter!=NULL) {
            if (oriIter->random != NULL)
                oriIter->next->random = oriIter->random->next;
            oriIter = oriIter->next->next;
        }  // add random
        
        pseudoHead = new RandomListNode(0);
        curIter = pseudoHead;
        oriIter = head;
        
        while (oriIter!=NULL) {
            next = oriIter->next->next;
        	// split the copy
            curIter->next = oriIter->next;
            curIter = oriIter->next;

        	// restore the original list
        	oriIter->next = next;
        	oriIter = next;
    	}
        curIter = pseudoHead->next;
        delete pseudoHead;
        return curIter;
    }
};

