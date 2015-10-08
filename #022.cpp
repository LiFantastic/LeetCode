/*============================================================
Problem: Generate Parentheses
==============================================================
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
============================================================*/
class Solution {
    vector<string> res;
    string tmp;

private:
    void generate(int leftCount, int rightCount) {
        if (leftCount==0 && rightCount==0)  
            res.push_back(tmp);
        if (leftCount>0) { // can generate left parentheses
            tmp += '('; 
            generate(leftCount-1, rightCount);
            tmp = tmp.substr(0, tmp.size()-1);
        } 
        if (rightCount>0 && leftCount<rightCount) { // can generate right parentheses  
            tmp += ')'; 
            generate(leftCount, rightCount-1);
            tmp = tmp.substr(0, tmp.size()-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        
        generate(n, n);
        return res;
    }
};