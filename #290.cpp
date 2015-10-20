/*============================================================
Problem: Word Pattern
==============================================================
Given a pattern and a string str, find if str follows the same 
pattern.

Here follow means a full match, such that there is a bijection 
between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
============================================================*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.size(), len = str.size();
        unordered_map<char, string> pattern2str;
        unordered_set<string> hasStr;
        
        int j = 0;
        for (int i=0; i<n; i++) {
            char p = pattern[i];
            string s = "";
            while (j<len && str[j]!=' ')
                s += str[j++];
            j++;
            
            if (s == "") return false;
            
            auto it = pattern2str.find(p);
            if (it==pattern2str.end()) {
                if (hasStr.count(s)) return false;
                else {
                    pattern2str[p] = s;
                    hasStr.insert(s);
                }
            }
            else if (it->second!=s) return false;
        }
        return j==len+1;
    }
};