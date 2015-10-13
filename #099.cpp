/*============================================================
Problem: Recover Binary Search Tree
==============================================================
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?
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
    TreeNode *firstElement = NULL;
    TreeNode *secondElement = NULL;
    
    TreeNode *prevElement = new TreeNode(INT_MIN);
    
    void traverse(TreeNode* root) {
        if (root == NULL) return;

        traverse(root->left);

        if (firstElement == NULL  && prevElement->val > root->val) firstElement = prevElement;
        if (firstElement != NULL && prevElement->val > root->val) secondElement = root;
        // determin the second element is a litter bit tricky
        prevElement = root;
        
        traverse(root->right);
    }
    
public: 
    void recoverTree(TreeNode* root) {

        // In order traversal to find the two elements
        traverse(root);
        // Swap the values of the two nodes
        swap(firstElement->val, secondElement->val);
    }
};
    