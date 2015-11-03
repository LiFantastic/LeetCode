/*============================================================
Problem: Convert Sorted Array to Binary Search Tree
==============================================================
Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
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
    TreeNode* convert(vector<int>::iterator left, vector<int>::iterator right) {
        if (left>=right) return NULL;
        
        vector<int>::iterator current = left+(right-left)/2;
        TreeNode *root = new TreeNode(*current);
        root->left = convert(left, current);
        root->right = convert(current+1, right);
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums.begin(), nums.end());
    }
};