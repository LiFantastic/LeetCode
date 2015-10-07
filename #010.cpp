/*============================================================
Problem: Regular Expression Matching
==============================================================
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
============================================================*/
/* a DP solution
Define the state P[i][j] to be true if s[0:i) matches p[0:j) 
and false otherwise. Then the state equations are:

P[i][j] = P[i-1][j-1]										p[j-1] != '*' && (s[i-1] == p[j-1] || p[j-1] == '.')
P[i][j] = P[i][j-2] 										p[j-1] == '*' 		(consider pattern repeats for 0 time)
P[i][j] = P[i-1][j] && (s[i-1]==p[j-2]||p[j-2]=='*')		p[j-1] == '*' 	(consider pattern repeats for at least 1 time)						*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp(m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for (int i=0; i<=m; i++)
            for (int j=1; j<= n; j++)
                if (p[j-1] == '*' && j>1)
                    dp[i][j] = dp[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                	// pattern * match 0 char from string s    ||    pattern * match 1 char from s (this can grow in the next iteration)
                else 
                	dp[i][j] = i>0 && dp[i-1][j-1] && (s[i-1]==p[j-1]||p[j-1]=='.');
                	// index detection	  &&    the prefix matches    &&    char at [i][j] matches
        return dp[m][n];
    }
};

// without DP, a recursive solution:
class Solution {
private:
	int lenS, lenP;

    bool isMatchSub(string s, int curS, string p, int curP) {
        if (curP==lenP) return curS==lenS; // pattern is empty, match string should be empty
        
        if (curP+1<lenP && p[curP+1] == '*') { // the next char in pattern is '*'
            while ((curS<lenS) && (s[curS]==p[curP]||p[curP]=='.')) { // s[curS] matches with p[curP]
                if (isMatchSub(s, curS, p, curP+2)) return true; // try matching * in pattern p with 0-more char in s
                curS++;
            }
            return isMatchSub(s, curS, p, curP+2);
        }
        else
            return (curS<lenS) && (s[curS]==p[curP]||p[curP]=='.') && isMatchSub(s, curS+1, p, curP+1); // match one char ahead
    }
public:
    bool isMatch(string s, string p) {
    	lenS = s.size();
    	lenP = p.size();
        return isMatchSub(s, 0, p, 0);
    }
};
