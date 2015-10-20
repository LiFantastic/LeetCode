/*============================================================
Problem: Kth Smallest Element in a BST
==============================================================
Given a binary search tree, write a function kthSmallest to 
find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Hint:
Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
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
public:
	int calcTreeSize(TreeNode* root){
		if (root == NULL) return 0;
		return 1+calcTreeSize(root->left) + calcTreeSize(root->right);		
	}
	int kthSmallest(TreeNode* root, int k) {
		// if (root == NULL) return 0;
		int leftSize = calcTreeSize(root->left);
		if (k == leftSize+1) return root->val;
		else if (leftSize >= k) return kthSmallest(root->left,k);
		else return kthSmallest(root->right, k-leftSize-1);
	}
};