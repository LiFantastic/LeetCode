/*============================================================
Problem: Minimum Window Substring
==============================================================
Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, 
return the empty string "".

If there are multiple such windows, you are guaranteed that 
there will always be only one unique minimum window in S.
============================================================*/
class Solution {
private:
    bool needed[256] = {false};
    int  counts[256] = {0};
public:
    string minWindow(string s, string t) {
    	int sLen = s.size(), tLen = t.size();
        if (sLen==0 || tLen==0) return "";
        
        for (int i=0; i<tLen; i++) {
            needed[t[i]] = true;
            counts[t[i]]++;
        }
        int start=0, minSize = INT_MAX, minStart, notMatchCount=tLen;  // start: the start index of the current WINDOW
        for (int i=0; i<sLen; i++) {
            if (needed[s[i]]) {  // vist a char we have to match
                counts[s[i]]--;
                if (counts[s[i]] >= 0)  // if another useful match is made, not matched minus 
                    notMatchCount--;
            }
            if (notMatchCount==0) {  // now we can move the start of the WINDOW forward, when all matched
                while (true) {
                    if (needed[s[start]]) {  // the first char is a char we have to match
                        if (counts[s[start]] < 0)  // have more matched ones of this char, can still move forward
                            counts[s[start]]++;
                        else
                            break;
                    }
                    // if the first char is not what we want to match, just move forward
                    start++;
                }
                if (minSize > i-start+1) {  // update the minimum WINDOW
                    minSize = i-start+1;
                    minStart = start;
                }
            }
        }
        return minSize==INT_MAX ? "" : s.substr(minStart, minSize);        
    }
};