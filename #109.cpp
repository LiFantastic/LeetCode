/*============================================================
Problem: Convert Sorted Array to Binary Search Tree
==============================================================
Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
============================================================*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* nodeVisiting;

    TreeNode *buildTree(int l, int r) {
        if (l>r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode *left = buildTree(l, mid-1);
        TreeNode *root = new TreeNode(nodeVisiting->val);
        root->left = left;
        nodeVisiting = nodeVisiting->next;  // key point here!
        root->right = buildTree(mid+1, r);
        return root;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            p = p->next;
            len++;
        }
        nodeVisiting = head;
        return buildTree(0, len-1);
    }
};