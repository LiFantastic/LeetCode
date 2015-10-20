/*============================================================
Problem: Binary Tree Paths
==============================================================
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:
["1->2->5", "1->3"]
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
    vector<string> res;
    string tmp;
    
    void getPaths(TreeNode* root) {
        tmp += to_string(root->val);
        if(!root->left && !root->right) {
            res.push_back(tmp);
            return;
        }
        string rememberTmp = tmp; 
        if(root->left) {
            tmp += "->";
            binaryTreePaths(root->left);
            tmp = rememberTmp;
        }
        if(root->right) {
            tmp += "->";
            binaryTreePaths(root->right);
            tmp = rememberTmp;
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        getPaths(root);
        return res;
    }
};