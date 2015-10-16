/*============================================================
Problem: Binary Tree Postorder Traversal
==============================================================
Given a binary tree, return the postorder traversal of its 
nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> nodeStack;
		TreeNode *tmp;
    	nodeStack.push(root);

    	while (!nodeStack.empty()) {
    		tmp = nodeStack.top();
    		nodeStack.pop();
    		if (!tmp) continue;
    		res.push_back(tmp->val);
    		nodeStack.push(tmp->left);
    		nodeStack.push(tmp->right);
    	}
    	reverse(res.begin(), res.end());
        return res;
    }
};