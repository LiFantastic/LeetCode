/*============================================================
Problem: Palindrome Partitioning
==============================================================
Given a string s, partition s such that every substring of the 
partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
============================================================*/
class Solution {
private:
	vector<string> tmp;
	vector<vector<string>> res;
	
    void getPartition(string& s, int idx) {
        if (idx == s.length()) {
            res.push_back(tmp);
            return;
        }
        for (int i=idx, n=s.length(); i<n; i++) {
            int l = idx, r = i;
            while (l<r && s[l]==s[r]) l++, r--;
            if (l>=r) {
                tmp.push_back(s.substr(idx, i-idx+1));
                getPartition(s, i+1);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        getPartition(s, 0);
        return res;
    }
};