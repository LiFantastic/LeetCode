/*============================================================
Problem: Word Ladder
==============================================================
Given two words (beginWord and endWord), and a dictionary's 
word list, find the length of shortest transformation sequence 
from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list

For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
============================================================*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {

        int wordLen = beginWord.size();
        if (!wordDict.count(beginWord) || !wordDict.count(endWord)) return 0;  // begin or end not in the Dict

        unordered_set<string> unusedWords = wordDict; // words that never visited before
        unordered_set<string> activeWords[3];
        int startSet = 0, endSet = 1, nextSet = 2, curDepth = 2, i;
        char tempChar, j;

        activeWords[startSet].insert(beginWord);
        activeWords[endSet].insert(endWord);
        unusedWords.erase(beginWord);
        unusedWords.erase(endWord);

        while (!activeWords[startSet].empty()) { // do BFS on startSet
            for (auto curWord : activeWords[startSet]) {
                for (i=0; i<wordLen; i++) {
                    for (tempChar=curWord[i], j='a'; j<='z'; j++) {
                        curWord[i] = j;
                        if (activeWords[endSet].count(curWord)>0) return curDepth;  // if the new word is in the endSet, then we find a path
                        if (unusedWords.count(curWord)) {  // otherwise, if curWord is a new word that has never been visited
                            activeWords[nextSet].insert(curWord);
                            unusedWords.erase(curWord); 
                        }
                    }// FOR j
                    curWord[i] = tempChar;
                } // FOR i
            } //FOR curWord
            curDepth++;
            swap(startSet, nextSet); // swap the startSet and the nextSet
            if (activeWords[startSet].size() > activeWords[endSet].size()) swap(startSet, endSet); // if needed, switch the search direction 
            activeWords[nextSet].clear();
        }
        return 0;  // no path found
    }
};