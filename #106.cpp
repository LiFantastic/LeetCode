/*============================================================
Problem: Construct Binary Tree from Inorder and Postorder Traversal
==============================================================
Given inorder and postorder traversal of a tree, construct the 
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
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
    	//IDEA: reverse of postorder: is visit the tree by order  root, root->right, root->left, quite similar to preorder
		int n = inorder.size();
		if (n==0) return NULL;

        stack<TreeNode*> nodeStack;
        TreeNode *root, *curParent;
        int i=n-2, j=n-1;
        bool constructRight = true;
        
		root = new TreeNode(postorder[n-1]);
        nodeStack.push(root);
        curParent = root;

        while (i>=0) {
            if (!nodeStack.empty() && nodeStack.top()->val==inorder[j]) {
                curParent = nodeStack.top();
                nodeStack.pop();
                constructRight = false;  // when a node is taken from the stack, we have already construted it's right
                j--;  // a node in inorder is visited (i doesn't decrease because no new node from preorder is created here)
            }
            else {
                if (constructRight) {
                    curParent->right = new TreeNode(postorder[i]);
                    curParent = curParent->right;
                }
                else {
                    curParent->left = new TreeNode(postorder[i]);
                    curParent = curParent->left;
					constructRight = true;  // start from construct right tree
                }
                nodeStack.push(curParent);
				i--;  // a node in preorder is created, decrease i (backward tranverse) 
            }
        }
        return root;
    }
};