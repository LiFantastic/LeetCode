/*============================================================
Problem: Word Break II
==============================================================
Given a string s and a dictionary of words dict, add spaces in
 s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
============================================================*/
class Solution {
private:
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if (m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if (dict.count(s)) //a whole string is a word
            result.push_back(s);
        for(int i=1; i<s.size(); i++) {
            string word=s.substr(i);
            if (dict.count(word)) {
                string rest=s.substr(0,i);
                vector<string> prev = combine(word, wordBreak(rest, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};