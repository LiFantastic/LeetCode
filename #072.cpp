/*============================================================
Problem: Edit Distance
==============================================================
Given two words word1 and word2, find the minimum number of 
steps required to convert word1 to word2. (each operation is 
counted as 1 step.)

You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
============================================================*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
        
        vector<vector<int>> D(len1+1, vector<int>(len2+1));
        
        for (int i=0; i<=len1; i++) D[i][0] = i;
        for (int j=0; j<=len2; j++) D[0][j] = j;
            
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                if (word1[i-1]==word2[j-1]) D[i][j] = D[i-1][j-1];
                else D[i][j] = min(min(D[i-1][j-1], D[i-1][j]), D[i][j-1])+1;
            }
        }
        return D[len1][len2];
    }
};