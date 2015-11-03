/*============================================================
Problem: Flatten Binary Tree to Linked List
==============================================================
Given a binary tree, flatten it to a linked list in-place.

For example,
Given
         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void flatten(TreeNode* root) {
        if (root==NULL) return;
            
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode *dummyHead = new TreeNode(0), *cur, *pre = dummyHead;
        
        while (!nodeStack.empty()) {
            // preOrder tranverse
            cur = nodeStack.top();
            nodeStack.pop();
            pre->right = cur;  // flattern
            pre->left = NULL;  // flattern
            pre = cur;
            if (cur->right!=NULL) nodeStack.push(cur->right);
            if (cur->left !=NULL) nodeStack.push(cur->left);
        }
        delete dummyHead;
    }
};