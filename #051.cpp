/*============================================================
Problem: N-Queens
==============================================================
The n-queens puzzle is the problem of placing n queens on an 
n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the 
n-queens' placement, where 'Q' and '.' both indicate a queen 
and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
============================================================*/
class Solution {
private:
    vector<vector<string>> res;
	vector<int> queens;  // queens[i] = j  means there is a queen at position (i, j)
	int n;

    void dfs (int row) {
        if (row == n) {
            vector<string> tmp(n, string(n, '.'));
            for (int i=0; i<n; i++)
                tmp[i][queens[i]] = 'Q';
            res.push_back(tmp);
            return;
        }
        for(int col=0; col<n; col++) {
        	if (isValid(row, col)) {
            	queens[row] = col;
            	dfs(row+1);
            	queens[row] = -1;;
        	} 
    	}
    }
 
    bool isValid(int row, int col) {
        for (int i=0; i<row; i++)  // only have to check the upper rows (lower rows not modified yet)
            if (queens[i]==col || abs(row-i)==abs(col-queens[i]))
                return false;
        return true;
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        this->n = n;
        queens = vector<int>(n, -1);
        dfs(0);
        return res;
    }
};