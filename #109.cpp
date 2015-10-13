/*============================================================
Problem: Convert Sorted List to Binary Search Tree
==============================================================
Given a singly linked list where elements are sorted in 
ascending order, convert it to a height balanced BST.
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
    int checkHeight(TreeNode* p) {  
    // return the height of subtree if it is banlanced, otherwise -1 for early pruning
        if (p==NULL) return 0;
        int leftHeight = checkHeight(p->left);
        if (leftHeight==-1) return -1;  // pruning
        int rightHeight = checkHeight(p->right);
        if (rightHeight==-1) return -1;  // pruning
        
        int heightDiff = abs(leftHeight-rightHeight);
        if (heightDiff>1) return -1;
        else return max(leftHeight, rightHeight)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (checkHeight(root)==-1) return false;
        else return true;
    }
};
