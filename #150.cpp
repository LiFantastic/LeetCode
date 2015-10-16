/*============================================================
Problem: Evaluate Reverse Polish Notation
==============================================================
Evaluate the value of an arithmetic expression in Reverse 
Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer 
or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
============================================================*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size(), res = 0;
        int num1, num2, num3;
        stack<int> operand;
        
        for (int i=0; i<n; i++) {
            string tmp = tokens[i];
            if (tmp.size()==1 && (tmp[0]<'0' || tmp[0]>'9')) {  // signs
                num2 = operand.top();
                operand.pop();
                num1 = operand.top();
                operand.pop();
                switch(tmp[0]) {
                    case '-': num3 = num1-num2; break;
                    case '+': num3 = num1+num2; break;
                    case '*': num3 = num1*num2; break;
                    case '/': num3 = num1/num2; break;
                }
                operand.push(num3);
            }
            else
                operand.push(atoi(tmp.c_str()));
        }
        return operand.top();
    }
};