/*============================================================
Problem: Path Sum II
==============================================================
Given a binary tree and a sum, find all root-to-leaf paths where 
each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> res;
    vector<int> tmp;
    
    void findPath(TreeNode* p, int target) {
        if (p==NULL) return;
        if (p->left==NULL && p->right==NULL && p->val==target) {
            tmp.push_back(target);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        int v = p->val, newTarget = target-v;
        if (p->left!=NULL) {
            tmp.push_back(v);
            findPath(p->left, newTarget);
            tmp.pop_back();
        }
        if (p->right!=NULL) {
            tmp.push_back(v);
            findPath(p->right, newTarget);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        findPath(root, sum);
        return res;
    }
};