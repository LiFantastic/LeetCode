/*============================================================
Problem: Populating Next Right Pointers in Each Node II
==============================================================
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your 
previous solution still work?

Note:
You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
============================================================*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *upperCur = root, *lowerPre, *lowerCur, *lowerFirst, *tmp[2];
        
        while (upperCur) {
            lowerPre = NULL;
            lowerFirst = NULL;

            while (upperCur) {
            	tmp[0] = upperCur->left;
            	tmp[1] = upperCur->right;
            	for (int i=0; i<2; i++) {
                	if (tmp[i]) {
                    	if (!lowerFirst) {
                        	lowerPre = tmp[i];
                        	lowerFirst = tmp[i];
                    	}
                    	else {
                        	lowerPre->next = tmp[i];
                        	lowerPre = tmp[i];
                    	}
               	 	}
               	}
                upperCur = upperCur->next;
            }
            upperCur = lowerFirst;
        }
    }
};