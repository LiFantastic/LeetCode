/*============================================================
Problem: Text Justification
==============================================================
Given an array of words and a length L, format the text such 
that each line has exactly L characters and is fully (left 
and right) justified.

You should pack your words in a greedy approach; that is, pack
 as many words as you can in each line. Pad extra spaces ' ' 
 when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly 
as possible. If the number of spaces on a line do not divide 
evenly between words, the empty slots on the left will be 
assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and 
no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
============================================================*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        vector<string> res;
        int i = 0, n = words.size();
        while (i<n) {
            int lineLen=0;
            int firstWordIndex = i;
            while (i<n) {
                int lineLenTmp = lineLen==0 ? words[i].size() : lineLen+1+words[i].size();
                if (lineLenTmp <= L)
                    lineLen = lineLenTmp;
                else
                    break;
                i++;
            }  // this line contains words in [firstWordIndex : i)
            int moreSpace = L-lineLen, eachSpace;
            if (i-firstWordIndex!=1 && i != n) {  // not a line with a single word AND not the last line  
                eachSpace = moreSpace / (i-1-firstWordIndex);
                moreSpace %= (i-1-firstWordIndex);
            }
            else
                eachSpace = 0;
            string s=words[firstWordIndex];
            for (int j=firstWordIndex+1; j<i; j++) {
                for(int k=0; k<=eachSpace; k++)
                    s += ' ';
                if (moreSpace>0 && i!=n) {  // if not the last line, allocate the remain spaces (recorded in moreSpace) to the first spaces
                    s += ' ';
                    moreSpace--;
                }
                s += words[j];
            }
                
            for (int j=0; j<moreSpace; j++)  // if the last line, there will be more spaces at last 
                s += ' ';   
            res.push_back(s);
        }
        return res;
    }
};