/*============================================================
Problem: Basic Calculator
==============================================================
Implement a basic calculator to evaluate a simple expression 
string.

The expression string may contain open ( and closing parentheses ), 
the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
============================================================*/
class Solution {
public:
    int calculate(string s) {
        stack<int> signs;   // stack for previous signs
        int curSign = 1, tmp = 0, res = 0;

        signs.push(1);  // for all the signs those are not in the parentheses

        for (auto c: s) {
            if (c=='(') signs.push(curSign);  // save the sign just before the '('
            else if (c==')') signs.pop();
            
            if (c>='0' && c<='9')  tmp = tmp*10+c-'0';  // calculate one num
            
            if (c=='-' || c=='+') {
                res += curSign*tmp;  // add the number before current sign to result
                tmp = 0;
                curSign = (c=='+' ? 1 : -1)*signs.top();  // determin current sign according to previous
            }
        }
        res+=curSign*tmp;  // in case tmp!=0

        return res;
    }
};