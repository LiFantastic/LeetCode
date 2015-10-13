/*============================================================
Problem: Word Ladder II
==============================================================
Given two words (beginWord and endWord), and a dictionary's 
word list, find all shortest transformation sequence(s) from 
beginWord to endWord, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the word list

For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
============================================================*/
struct Node {
    string word;
    vector<Node*> parent;
    
    Node(string w) {
        word = w;
        parent.clear();
    }
};
class Solution {
private:
    void generatePath(vector<vector<string>>& res, vector<string>& tmp, Node* p) {
        int n = p->parent.size();
        if (n==0) { 
            res.push_back(tmp);
            return;
        }
        for (int i=0; i<n; i++) {
            tmp.push_back(p->parent[i]->word);
            //tmp.insert(tmp.begin(), p->parent[i]->word);
            generatePath(res, tmp, p->parent[i]);
            tmp.pop_back();
            //tmp.erase(tmp.begin());
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
        vector<Node*> curLevel;
        vector<Node*> nextLevel;
        
        vector<vector<string>> res;
        map<string, Node*> word2node;
        
        swap(beginWord, endWord);
        
        int levelSize, wordSize = beginWord.size();
        bool found = false;
        
        Node *curL, *nextL;
        
        curL = new Node(beginWord);
        curLevel.push_back(curL);
        
        wordList.erase(beginWord);
        wordList.insert(endWord);
        
        while (!curLevel.empty() && !found) {
            nextLevel.clear();
            word2node.clear();
            
            levelSize = curLevel.size();
            for (int i=0; i<levelSize; i++) {
                curL = curLevel[i];
                string word = curL->word; // upper level
                for (int j=0; j<wordSize; j++) {
                    char oldchar = word[j];
                    for (word[j]='a'; word[j]<='z'; word[j]++) {
                        if (wordList.count(word)) { // now we found a valid child-word, let's yield a child.
                            if (!found && word==endWord)
                                found = true;
                            map<string, Node*>::iterator it = word2node.find(word);
                            if (it==word2node.end()) {
                                nextL = new Node(word);
                                word2node[word] = nextL;
                                nextLevel.push_back(nextL);
                            }
                            else
                                nextL = it->second;
                            nextL->parent.push_back(curL);
                        }
                    }
                    word[j] = oldchar;
                }
            }
            for (int i=0; i<nextLevel.size(); i++)
                wordList.erase(nextLevel[i]->word);
            curLevel = nextLevel;
        }
        if (!found) return res;
        
        curL =  word2node.find(endWord)->second;
        vector<string> tmp(1, endWord);
        generatePath(res, tmp, curL);
        return res;
    }
};