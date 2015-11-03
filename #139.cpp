/*============================================================
Problem: Word Break
==============================================================
Given a string s and a dictionary of words dict, determine if 
s can be segmented into a space-separated sequence of one or 
more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
============================================================*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> result(s.length(), false);
        for (int i = 0; i < result.size(); ++i) {
            if (dict.find(s.substr(0, i + 1)) != dict.end()) {
                result[i] = true;
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if ((result[j] == true) && (dict.find(s.substr(j+1, i-j))!= dict.end())) {
                    result[i] = true;
                    break;
                }
            }
        }
        return result[result.size() - 1];
    }
};