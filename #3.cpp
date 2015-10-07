/*============================================================
Problem: Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring 
without repeating characters. 
For example, the longest substring without repeating letters 
for "abcabcbb" is "abc", which the length is 3. For "bbbbb" 
the longest substring is "b", with the length of 1.
============================================================*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastLoc[256]; // the last appeared location of character indexed by ASCII  
        memset(lastLoc, -1, sizeof(lastLoc));  // -1 indicate not exist

        int idx=-1, maxLen=0, len=s.size();
        
        for (int i=0; i<len; i++) {
            if (lastLoc[s[i]] > idx)
                idx = lastLoc[s[i]];
            maxLen = max(maxLen, i-idx);
            if ((idx+maxLen)>len) // no possible for longer result
                break;
            lastLoc[s[i]] = i; // update the last appeared location
        }
		return maxLen;
    }
};