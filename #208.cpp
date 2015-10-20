/*============================================================
Problem: Implement Trie (Prefix Tree)
=====================================`=========================
Implement a trie with insert, search, and startsWith methods.
============================================================*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():isWord(false){
        memset(next, 0, sizeof(next));
    }
    TrieNode* next[26];
    bool isWord;
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        int index;

        for (char c:word) {
            index = c-'a';
            if (p->next[index] == NULL)
            	p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        int index;

        for(char c:word) {
            index = c-'a';
            if (p->next[index] == NULL)
                return false;
            p = p->next[index];
        }
        return p->isWord;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        int index;

        for(char c:prefix) {
            index = c-'a';
            if (p->next[index] == NULL)
                return false;
            p = p->next[index];
        }
        return true;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");