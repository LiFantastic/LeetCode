/*============================================================
Problem: Decode Ways
==============================================================
A message containing letters from A-Z is being encoded to numbers 
using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total 
number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) 
or "L" (12).

The number of ways decoding "12" is 2.
============================================================*/
class Solution {
private:
    bool twoDigitsValid(char num1, char num2) {
    	return num1!='0' && ((num1-'0')*10+num2-'0')<=26;
    }
public:
    int numDecodings(string s) {
        if (s.size()==0) return 0;
        else if (s.size()==1) return s[0] != '0' ? 1 : 0;
        else if(s.size() == 2) return (s[0] != '0' && s[1] != '0' ? 1 : 0) + (twoDigitsValid(s[0], s[1]) ? 1 : 0);

        vector<int> dp(s.size());
        dp[0] = s[0] != '0' ? 1 : 0;
        dp[1] = (s[0] != '0' && s[1] != '0' ? 1 : 0) + (twoDigitsValid(s[0], s[1]) ? 1 : 0);
        for (int i=2; i<s.size(); i++) {
            dp[i] = 0;
            if (s[i] != '0') dp[i] += dp[i-1];
            if (twoDigitsValid(s[i-1], s[i])) dp[i] += dp[i-2];
        }
        
        return dp[s.size()-1];
    }
};