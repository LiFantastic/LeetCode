/*============================================================
Problem: Construct Binary Tree from Preorder and Inorder Traversal
==============================================================
Given preorder and inorder traversal of a tree, construct the 
binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
 class Solution {  // a non recursive solution
public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size()==0) return NULL;

        stack<TreeNode*> nodeStack;
        TreeNode *root, *curParent;
        int i=1, j=0;
        bool constructLeft = true;
        
		root = new TreeNode(preorder[0]);
        nodeStack.push(root);
        curParent = root;

        while (i<preorder.size()) {
            if (!nodeStack.empty() && nodeStack.top()->val==inorder[j]) {
                curParent = nodeStack.top();
                nodeStack.pop();
                constructLeft = false;  // when a node is taken from the stack, we have already construted it's left
                j++;  // a node in inorder is visited (i doesn't increase because no new node from preorder is created here)
            }
            else {
                if (constructLeft) {
                    curParent->left = new TreeNode(preorder[i]);
                    curParent = curParent->left;
                }
                else {
                    curParent->right = new TreeNode(preorder[i]);
                    curParent = curParent->right;
					constructLeft = true;  // start from construct left tree
                }
                nodeStack.push(curParent);
				i++;  // a node in preorder is created, increase i 
            }
        }
        return root;
    }
};