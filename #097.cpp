/*============================================================
Problem: Interleaving String
==============================================================
Given s1, s2, s3, find whether s3 is formed by the interleaving 
of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
============================================================*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int m = s1.length();
		int n = s2.length();
		if (m+n != s3.length()) return false;
		
		vector<vector<bool>> notAdded(m+1, vector<bool>(n+1, true));
		stack<vector<int>> indexStack;
		vector<int> index(2);
		index[0] = 0;
		index[1] = 0;
		
		indexStack.push(index);
	
		while (!indexStack.empty()) {
		    index = indexStack.top();
		    indexStack.pop();
		    int i = index[0];
		    int j = index[1];
		    if (i==m && j==n) return true;
		    
		    if (i<m && s1[i]==s3[i+j] && notAdded[i+1][j]) {
		        index[0] = i+1;
		        index[1] = j;
		        notAdded[i+1][j] = false;
		        indexStack.push(index);
		    }
		    if (j<n && s2[j]==s3[i+j] && notAdded[i][j+1]) {
		        index[0] = i;
		        index[1] = j+1;
		        notAdded[i][j+1] = false;
		        indexStack.push(index);
		    }
		}
		return false;
    }
};