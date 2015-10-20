/*============================================================
Problem: Add and Search Word - Data structure design
==============================================================
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression 
string containing only letters a-z or .. A . means it can represent 
any one letter.

For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
============================================================*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():isWord(false) {
        memset(next, 0, sizeof(next));
    }
    TrieNode* next[26];
    bool isWord;
};
class WordDictionary {
private:
    TrieNode* root;
    
    bool searchNode(TrieNode *p, string str) {
        if (p->isWord && str.size()==0) return true;
        else if (str.size()==0) return false;
        else {
            char c = str[0];
            if (c!='.') {
                int index = c-'a';
                if (p->next[index]==NULL) return false;
                else return searchNode(p->next[index], str.substr(1));
            }
            else {
                for (int i=0; i<26; i++) {
                    if (p->next[i]!=NULL && searchNode(p->next[i], str.substr(1)))
                        return true;
                }
                return false;
            }
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode*p = root;
        int index;

        for(char c:word) {
            index = c-'a';
            if(p->next[index] == NULL)
                p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchNode(root, word);
    }
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");