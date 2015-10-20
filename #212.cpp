/*============================================================
Problem: Word Search II
==============================================================
Given a 2D board and a list of words from the dictionary, find 
all words in the board.

Each word must be constructed from letters of sequentially 
adjacent cell, where "adjacent" cells are those horizontally or
 vertically neighboring. The same letter cell may not be used 
 more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
============================================================*/
// impovement: each search (dfs) don't have to start from the top
// impovement: for duplicate, mark the dict isword to avoid 
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
class Trie {
public:
	TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    TrieNode* searchNode(TrieNode *p, char c) {
    	return p->next[c-'a'];
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
};
class Solution {
    Trie dict;
   	vector<string> res;
    string tmp="";
    vector<vector<bool>> used;
    int m, n;
    
    void dfs(int i, int j, TrieNode* p, vector<vector<char>>& board) {
    	p = dict.searchNode(p, board[i][j]);
    	tmp += board[i][j];
        used[i][j] = true;
        if (p) {  // prefix matched
    		if (p->isWord) {
    			res.push_back(tmp);
    			p->isWord = false;
    		}
            if (i-1>=0 && !used[i-1][j])
                dfs(i-1, j, p, board);
            if (i+1<m && !used[i+1][j])
                dfs(i+1, j, p, board);
            if (j-1>=0 && !used[i][j-1])
                dfs(i, j-1, p, board);
            if (j+1<n && !used[i][j+1])
                dfs(i, j+1, p, board);
        }
        tmp = tmp.substr(0, tmp.size()-1);
        used[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        if (m==0) return res;
        n = board[0].size();
        if (n==0) return res;

        for (int i=0; i<words.size(); i++) dict.addWord(words[i]);
        used = vector<vector<bool>>(m, vector<bool>(n));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++)
                dfs(i, j, dict.root, board);
        }
        return res;
    }
};