/*============================================================
Problem: Longest Palindromic Substring
==============================================================
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there 
exists one unique longest palindromic substring.
============================================================*/
class Solution {
private:
    string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2;
        int n = s.length();
        while (l >= 0 && r <= n-1 && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n==0) return "";
        string res = s.substr(0, 1);  // a single char itself is a palindrome
        for (int i=0; i<n-1; i++) {
            string tmp = expandAroundCenter(s, i, i);
            if (tmp.length() > res.length())
                res = tmp;
            tmp = expandAroundCenter(s, i, i+1);
            if (tmp.length() > res.length())
                res = tmp;
        }
        return res;
    }
};