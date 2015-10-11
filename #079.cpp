/*============================================================
Problem: Word Search
==============================================================
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent 
cell, where "adjacent" cells are those horizontally or vertically 
neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
============================================================*/
class Solution {
private:
    int m;
    int n;
    vector<vector<char>> board;
    string word;
    
    bool dfs (vector<vector<char>>& board, const char* word, int x, int y) {
        if (board[x][y] != *word) return false;
		if (*(word+1)=='\0') return true;
        
        char curChar = board[x][y];
        board[x][y] = '*';  // used
        bool res = false;

        if (!res && x>0) res = dfs(board, word+1, x-1, y);
        if (!res && x<m-1) res = dfs(board, word+1, x+1, y);
        if (!res && y>0) res = dfs(board, word+1, x, y-1);
        if (!res && y<n-1) res = dfs(board, word+1, x, y+1);
        
        board[x][y] = curChar;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if (m==0) return false;
        n = board[0].size();
        if (n==0) return false;
        
        this->board = board;
        this->word = word;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (dfs(board, word.c_str(), i, j))  // visiting c_str (char* type) is faster than visiting string type
                    return true;
            }
        }
        return false;
    }
};