/*============================================================
Problem: Basic Calculator II
==============================================================
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / 
operators and empty spaces . The integer division should truncate 
toward zero.

You may assume that the given expression is always valid.
============================================================*/
class Solution {
public:
	int calculate(string s) {
		istringstream in(s);
		int res = 0, tmp, sign = 1, n;
		char op;
		in >> tmp;
		while (in >> op) {
 	     	if (op == '+' || op == '-') {
    	    	res += sign * tmp;
        		sign = 44 - op; //op == '+' ? 1 : -1
        		in >> tmp;
      		} 
      		else {
        		in >> n;
        		if (op == '*')
          			tmp *= n;
        		else
          			tmp /= n;
      		}
    	}
    	res += sign * tmp;
  	  	return res;
  	}
};