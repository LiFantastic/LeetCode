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

    bool check(int val) {  // in order tranverse, prev should aways smaller than val
        if (prev>=val) return false;
        prev = val;
        return true;
    }
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        return (isValidBST(root->left) && check(root->val) && isValidBST(root->right));
        // in order tranverse
    }
};