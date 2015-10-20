/*============================================================
Problem: Shortest Palindrome
==============================================================
Given a string S, you are allowed to convert it to a palindrome 
by adding characters in front of it. Find and return the shortest 
palindrome you can find by performing this transformation.

For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
============================================================*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string str = s + "#" + rev_s;

        vector<int> next(str.size(), 0);  // next[i] = j means when visit i+1 should compare with str[j] to see if has common prefix
        
        // find "next" of str, then the prefix is the longest Palindrome prefix in origin s
        for (int i=1; i<str.size(); i++) {
            int toCompare = next[i-1];
            while (toCompare > 0 && str[i] != str[toCompare])  // doesn't match
                toCompare = next[toCompare-1];
            next[i] = (toCompare += str[i]==str[toCompare]);
        } 
        
        return rev_s.substr(0, s.size()-next[str.size()-1]) + s;
    }
};