/*============================================================
Problem: Distinct Subsequences
==============================================================
Given a string S and a string T, count the number of distinct 
subsequences of T in S.

A subsequence of a string is a new string which is formed from 
the original string by deleting some (can be none) of the 
characters without disturbing the relative positions of the 
remaining characters. (ie, "ACE" is a subsequence of "ABCDE" 
while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"
Return 3.
============================================================*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        /* appearance: locations of each characters appeared in string T.
         * Each indices of same character are arranged in Descending order. 
         * An example:
         * T 			is 	[ r a b b i t ]
         * appearance 	is 	[ r:0 a:1 b:3,2 i:4 t:5]
         */
        unordered_map<char, vector<int>> appearance;
        for (int i=m-1; i>=0; i--)
            appearance[t[i]].push_back(i);
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        
        for (int i=0; i<n; i++) {
        	auto it = appearance.find(s[i]);
            if (it == appearance.end()) continue;
            vector<int> indices = it->second;
            for (int j=0; j<indices.size(); j++)
                dp[indices[j]+1] += dp[indices[j]];
        }
        return dp[m];
    }
};