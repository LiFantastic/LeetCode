/*============================================================
Problem: Validate Binary Search Tree
==============================================================
Given a binary tree, determine if it is a valid binary search 
tree (BST).

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less 
than the node's key.
The right subtree of a node contains only nodes with keys 
greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
class Solution {  // in order traverse
private:
    long prev = LONG_MIN;

    bool inOrderCheck(TreeNode *root) {  // in order tranverse, prev should aways smaller than val
        if (root == NULL) return true;
        if (!inOrderCheck(root->left)) return false;
        if (prev>=root->val) return false;
        prev = root->val;
        return inOrderCheck(root->right);
    }
public:
    bool isValidBST(TreeNode *root) {
        return inOrderCheck(root);
        // in order tranverse
    }
};