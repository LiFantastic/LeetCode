/*============================================================
Problem: Count Complete Tree Nodes
==============================================================
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the 
last, is completely filled, and all nodes in the last level 
are as far left as possible. It can have between 1 and 2h nodes 
inclusive at the last level h.
============================================================*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int getLeftHeight(TreeNode* root) {
    	int height = 0;
    	while (root) { 
        	root = root->left;
        	height++;
    	}
    	return height;
    }
    int getRightHeight(TreeNode* root) {
    	int height = 0;
    	while (root) { 
        	root = root->right;
        	height++;
    	}
    	return height;
    }
    int countWithHeight(TreeNode* root, int leftHeight, int rightHeight) {
        if (!root) return 0;
        if (leftHeight ==-1) leftHeight  = getLeftHeight(root->left);
        if (rightHeight==-1) rightHeight = getRightHeight(root->right);
        
        if (leftHeight==rightHeight) return (2<<leftHeight)-1;
        else return countWithHeight(root->left, leftHeight-1, -1)+countWithHeight(root->right, -1, rightHeight-1)+1;
    }
public:
int countNodes(TreeNode* root) {
        countWithHeight(root, -1, -1);
    }
};