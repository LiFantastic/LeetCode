/*============================================================
Problem: Binary Tree Inorder Traversal
==============================================================
Given a binary tree, return the inorder traversal of its nodes' 
values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode *tmp = root;

        while (!nodeStack.empty() || tmp) {
            if (tmp) {  // first time visit a node, put it into stack if it is not empty
                nodeStack.push(tmp);
                tmp = tmp->left;  // then visit it's left child
            }
            else {  
                tmp = nodeStack.top();  // second time visit a node
                nodeStack.pop();
                res.push_back(tmp->val);  // in-order tranverse
                tmp = tmp->right;  // visit it's right child
            }
        }
        return res;
    }
};