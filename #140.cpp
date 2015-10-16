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
    unordered_map<string, vector<string>> memory;

    vector<string> combine(vector<string> tmpRes, string word){
        for (int i=0;i<tmpRes.size();++i) {
            tmpRes[i]+=" "+word;
        }
        return tmpRes;
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if (memory.count(s)) return memory[s]; //take from memory
        vector<string> res;
        if (dict.count(s))  //a whole string is a word
            res.push_back(s);
        for (int i=1; i<s.size(); i++) {
            string word=s.substr(i);
            if (dict.count(word)) {
                string prev=s.substr(0,i);
                vector<string> tmp = combine(wordBreak(prev, dict), word);
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
        }
        memory[s]=res; //memorize
        return res;
    }
};