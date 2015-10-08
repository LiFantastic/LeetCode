/*============================================================
Problem: Implement strStr()
==============================================================
Implement strStr().

Returns the index of the first occurrence of needle in 
haystack, or -1 if needle is not part of haystack.
============================================================*/
// KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;
        // counting NEXT array for needle      
        vector<int> next(m, 0);

        for (int i=1; i<m; i++) {
            next[i] = next[i-1];
            while (next[i]>0 && needle[next[i]]!=needle[i])
                next[i] = next[next[i]-1];
            if (needle[next[i]] == needle[i])
                next[i]++;
        }
        // KMP
        int j = 0; // indext for needle
        for (int i=0; i<n; i++) { // index for haystack
            while (j>0 && needle[j]!=haystack[i])
                j = next[j-1];
            if (needle[j]==haystack[i]) j++;
            if (j== m)
                return i-m+1;
        }
        return -1;
    }
};

// simple solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0; ; i++) {
            for (int j=0; ; j++) {
                if (j == needle.length())
                    return i;
                if (i + j == haystack.length())
                    return -1;
                if (needle[j] != haystack[i+j])
                    break;
            }
        }
    }
};