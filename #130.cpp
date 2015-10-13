/*============================================================
Problem: Surrounded Regions
==============================================================
Given a 2D board containing 'X' and 'O', capture all regions 
surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that 
surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
============================================================*/
class Solution {
private:
    int row, col;
    
    void check(vector<vector<char> >&vec,int i,int j){
        if (vec[i][j]=='O') {
            vec[i][j]='R';  // mark it as 'R': Remain 'O' after processing
            if (i>1) check(vec, i-1, j);
            if (j>1) check(vec, i, j-1);
            if (i+1<row) check(vec, i+1, j);
            if (j+1<col) check(vec, i, j+1);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int i, j;
        row = board.size();
        if (!row) return;
        col=board[0].size();

        for (i=0; i<row; i++) {
            check(board, i, 0);
            if (col>1) check(board, i, col-1);
        }
        for (j=1; j+1<col; j++){
            check(board, 0, j);
            if (row>1) check(board, row-1, j);
        }
        for (i=0; i<row; i++) {
            for (j=0; j<col; j++) {
                if (board[i][j]=='O')
                	board[i][j]='X';
                if (board[i][j]=='R')
                    board[i][j]='O';
            }
        }
    }
};