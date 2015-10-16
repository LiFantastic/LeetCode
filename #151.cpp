/*============================================================
Problem: Reverse Words in a String
==============================================================
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading 
or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
============================================================*/
class Solution {
private:
    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string& s, int i, int j) {
        while (i<j) {char t=s[i]; s[i++]=s[j]; s[j--]=t;}
    }
public:
    void reverseWords(string &s) {
        int i=0, j=0, wordStart=0;  // i: index to scan the origin string; j: index to create the result
        int len=s.length();
        bool firstWord=true;

        while (true) {
            while (i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if (i==len) break;
            if (firstWord) firstWord = false;  // add one space between words
            else s[j++] = ' ';
            wordStart=j;
            while (i<len && s[i]!=' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s, wordStart, j-1);  // reverse letters in each word
        }
        s.resize(j);  // resize result string
        reverseword(s, 0, j-1);  // reverse whole string
    }
};