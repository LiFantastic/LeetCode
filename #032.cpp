/*============================================================
Problem: Longest Valid Parentheses
==============================================================
Given a string containing just the characters '(' and ')', find 
the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", 
which has length = 2.

Another example is ")()())", where the longest valid parentheses 
substring is "()()", which has length = 4.
============================================================*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indexStack;
        indexStack.push(-1);  // the elememt in the bottom means the pos ahead of the first '('
        int res = 0;
        for(int i=0; i<s.size(); i++) {
        	if (s[i] == '(')
                indexStack.push(i);
            else {
                if (indexStack.size()>1) {  // this means the corresponding '(' exists
                    indexStack.pop();  // pop index of '('
                    int tmp=indexStack.top();  // the pos ahead of the first successfully matched '('
                    res = max(res, i-tmp);
                }
                else {
                    indexStack.pop();  // update the front of the matche sequence
                    indexStack.push(i);
                }
            }
        }
        return res;
    }
};