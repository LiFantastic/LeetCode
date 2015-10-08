/*============================================================
Problem: Group Anagrams
==============================================================
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
============================================================*/
class Solution {
private:
    string getCode(string s) {
        sort(s.begin(), s.end());
        return s;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        sort(strs.begin(), strs.end());
        
        unordered_map<string, vector<string>> codeToStrs;
        
        for (int i = 0; i<strs.size(); i++)
            codeToStrs[getCode(strs[i])].push_back(strs[i]);
        
        for (auto it=codeToStrs.begin(); it!=codeToStrs.end(); it++)
            res.push_back(it->second);
        
        return res;
    }
};