/*============================================================
Problem: Unique Binary Search Trees II
==============================================================
Given n, generate all structurally unique BST's (binary search 
trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> res;
        if (r<l) res.push_back(NULL);
        else if (r==l) res.push_back(new TreeNode(l));
        else {
            for (int i=l; i<=r; i++) {  // i will be the root node, generate left and right child
                vector<TreeNode*> leftTree  = generate(l, i-1);
                vector<TreeNode*> rightTree = generate(i+1, r);

                for (int j=0; j<leftTree.size(); j++) {
                    for (int k=0; k<rightTree.size(); k++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = leftTree[j];
                        root->right = rightTree[k];  // combine all the possible left and right tree
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};