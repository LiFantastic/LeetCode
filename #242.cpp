/*============================================================
Problem: Valid Anagram
==============================================================
Given two strings s and t, write a function to determine if t 
is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you 
adapt your solution to such case?
============================================================*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length(), counts[256] = {0};
        for (int i=0; i<n; i++) { 
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (int i=0; i<256; i++) if (counts[i]) return false;
        return true;
    }
};