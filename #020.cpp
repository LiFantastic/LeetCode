/*============================================================
Problem: Valid Parentheses
==============================================================
Given a string containing just the characters '(', ')', 
'{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and 
"()[]{}" are all valid but "(]" and "([)]" are not.
============================================================*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        int i = 0;
        while (i < s.size()) {
            char c = s[i];
            if (c != ')' && c != '}' && c != ']')
                parentheses.push(c);
            else {
                if (parentheses.size() == 0)
                   return false;
                char pre = parentheses.top();
                switch(c) {
               		case ')':
                   		if (pre == '(')
                      		parentheses.pop();
                    	else 
                      		return false;
                    	break;
                	case '}':
                    	if (pre == '{')
                      		parentheses.pop();
                    	else 
                      		return false;
                    	break;
                	case ']':
                    	if (pre == '[')
                      		parentheses.pop();
                    	else 
                      		return false;
                    	break;
                }
            }
            i++;
        }
        if (parentheses.size() == 0)
        	return true;
        else 
        	return false;
    }
};