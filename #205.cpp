/*============================================================
Problem: Isomorphic Strings
==============================================================
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced 
to get t.

All occurrences of a character must be replaced with another 
character while preserving the order of characters. No two 
characters may map to the same character but a character may 
map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
============================================================*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> lastOccurInS(128, -1);
        vector<int> lastOccurInT(128, -1);
        if (s.size()!=t.size()) return false;
        
        int len = s.size();
        for (int i=0; i<len; i++) {
            if (lastOccurInS[s[i]]!=lastOccurInT[t[i]])  return false;
            lastOccurInS[s[i]] = i;
            lastOccurInT[t[i]] = i;
        }
        return true;
    }
};