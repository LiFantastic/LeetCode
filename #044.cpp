/*============================================================
Problem: Wildcard Matching
==============================================================
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
============================================================*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int indexS=0, indexP=0, lenS=s.size(), lenP=p.size();
        int lastStarP = -1, lastStarS;  //  the index of P and S when the last * occurs in P
        
        while (indexS<lenS) {
            if (indexP<lenP) {
                if (p[indexP]=='?' || s[indexS]==p[indexP]) {
                    indexS++;
                    indexP++;
                    continue;
                }
                if (p[indexP]=='*') {
                    lastStarP = indexP;
                    indexP++;
                    lastStarS = indexS;
                    continue;
                } // found a * and match 0 char from s
            }
            // enter following code means s[indexS] cant not match p[indexP], have to recover from last *
            if (lastStarP>-1) {
                indexP = lastStarP+1;
                indexS = ++lastStarS; // match one more char from s
                continue;
            }
            // no last * occured
            return false;
        }
        while (indexP<lenP) {
            if (p[indexP]!='*')
                return false;
            indexP++;
        }
        return true;
    }
};