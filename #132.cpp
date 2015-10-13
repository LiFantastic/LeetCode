/*============================================================
Problem: Palindrome Partitioning II
==============================================================
Given a string s, partition s such that every substring of the 
partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be 
produced using 1 cut.
============================================================*/
class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
         if (n<=1) return 0;
         int i,j;
         bool isPal[n][n] = {false};
         int dp[n+1];  // dp[i]: min cuts need for s[0:i) 

         for (i=0; i<=n; ++i) dp[i] = i-1;  // initial with len(s[0:i))-1 = i-1

         for (j=1; j<n; j++) {
             for (i=j; i>=0; i--) {
                 if ((s[i] == s[j]) && ((j-i < 2) || isPal[i+1][j-1])) {  // s[i:j] is pal
                     isPal[i][j] = true;
                     dp[j+1] = min(dp[j+1], 1 + dp[i]);  // update dp[j+1], with information of dp[i] (s[0:i-1] has length of i) 
                 }
             }
         }
         return dp[n];
     }
 };