/*============================================================
Problem: Binary Search Tree Iterator
==============================================================
Implement an iterator over a binary search tree (BST). Your 
iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time 
and uses O(h) memory, where h is the height of the tree.
============================================================*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *cur;
    stack<TreeNode*> nodeStack;
    int nextmin;
public:    
    BSTIterator(TreeNode *root) {
        // reconstruct the tree, each node's right child point to "next" element
        TreeNode *tmp = root;
        TreeNode *dummyHead = new TreeNode(0);
        cur = dummyHead;
        while (tmp) {
            if (tmp->left) {
                nodeStack.push(tmp);
                tmp = tmp->left;
                continue;
            }
            else {
                cur->right = tmp;
                cur = tmp;
                tmp = tmp->right;
                if (!tmp && !nodeStack.empty()) {
                    tmp = nodeStack.top();
                    tmp->left = NULL;
                    nodeStack.pop();
                }
            }
        }
        cur = dummyHead->right;
        delete dummyHead;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur;
    }
    /** @return the next smallest number */
    int next() {
        int res = cur->val;
        cur = cur->right;
        return res;
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */