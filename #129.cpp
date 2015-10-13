/*============================================================
Problem: Sum Root to Leaf Numbers
==============================================================
Given a binary tree containing digits from 0-9 only, each 
root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents 
the number 123.

Find the total sum of all root-to-leaf numbers.

For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int res;
    int tmp;
    
    void toLeafNum(TreeNode* p) {
        if (p==NULL) return;
        if (p->left==NULL && p->right==NULL) res += (tmp*10+p->val);
        if (p->left != NULL) {
            tmp = 10*tmp+p->val;
            toLeafNum(p->left);
            tmp /= 10;
        }
        if (p->right != NULL) {
            tmp = 10*tmp+p->val;
            toLeafNum(p->right);
            tmp /= 10;
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        tmp = 0;
        res = 0;
        toLeafNum(root);
        return res;
    }
};