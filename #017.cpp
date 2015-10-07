/*============================================================
Problem: Letter Combinations of a Phone Number
==============================================================
Given a digit string, return all possible letter combinations 
that the number could represent.

1			2:abc		3:def
4:ghi		5:jkl		6:mno
7:pqrs		8:tuv		9:wxyz

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your 
answer could be in any order you want.
============================================================*/
class Solution {
private:
    map<char, vector<char>> digit2letter;
    vector<string> res;
    string digits;
    string tmp;
    int digitsLen;

    void createMap() {
        digit2letter.clear();
        char digits[26] = { 'a', 'b', \
        'c', 'd', 'e', 'f', 'g', 'h', \
       	'i', 'j', 'k', 'l', 'm', 'n', \
       	'o', 'p', 'q', 'r', 's', 't', \
       	'u', 'v', 'w', 'x', 'y', 'z'  };
        digit2letter['2'] = vector<char>(digits   , digits+3);
        digit2letter['3'] = vector<char>(digits+3 , digits+6);
        digit2letter['4'] = vector<char>(digits+6 , digits+9);
        digit2letter['5'] = vector<char>(digits+9 , digits+12);
        digit2letter['6'] = vector<char>(digits+12, digits+15);
        digit2letter['7'] = vector<char>(digits+15, digits+19);
        digit2letter['8'] = vector<char>(digits+19, digits+22);
        digit2letter['9'] = vector<char>(digits+22, digits+26);
    }
    void dfs(int depth) {
        if (depth == digitsLen) {
            res.push_back(tmp);
            return;
        }
        auto letters = digit2letter[digits[depth]];
        for (int i=0; i<letters.size(); i++) {
        	tmp += letters[i];
            dfs(depth+1);
            tmp = tmp.substr(0, depth);
        }
    }
public:    
    vector<string> letterCombinations(string digits) {
    	res.clear();
        if (digits.size() == 0)
            return res;
        createMap();
        digitsLen = digits.size();
        this->digits = digits;
        dfs(0);
        return res;
    }
};