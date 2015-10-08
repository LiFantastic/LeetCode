/*============================================================
Problem: Substring with Concatenation of All Words
==============================================================
You are given a string, s, and a list of words, words, that are 
all of the same length. Find all starting indices of substring(s) 
in s that is a concatenation of each word in words exactly once 
and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
============================================================*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), cnt = words.size();
        if (n==0 || cnt==0) return res;

        // init word occurence
        unordered_map<string, int> wordCount;
        for (int i=0; i<cnt; i++) wordCount[words[i]]++;

        // travel all sub string combinations
        int wordLen = words[0].size();
        for (int i=0; i<wordLen; i++) {
            int leftIndex = i, count = 0;
            unordered_map<string, int> curWordCount;
            for (int curIndex=leftIndex; curIndex<=n-wordLen; curIndex+=wordLen) {
                string str = s.substr(curIndex, wordLen);
                // a valid word, accumulate results
                if (wordCount.count(str)) {
                    curWordCount[str]++;
                    count++;
                    // use str for too many times, advance the window leftIndex side possiablly
                    if (curWordCount[str] > wordCount[str]) {
                        string strTmp;
                        do {
                            strTmp = s.substr(leftIndex, wordLen);
                            curWordCount[strTmp]--;
                            count--;
                            leftIndex += wordLen;
                        } while (strTmp.compare(str)!=0);
                    }
                    // come to a result
                    if (count == cnt) {
                        res.push_back(leftIndex);
                        // advance one word
                        curWordCount[s.substr(leftIndex, wordLen)]--;
                        count--;
                        leftIndex += wordLen;
                    }
                }
                // not a valid word, move the window to the right side of the unvalid word
                else {
                    curWordCount.clear();
                    count = 0;
                    leftIndex = curIndex + wordLen;
                }
            }
        }
        return res;
    }
};