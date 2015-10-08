/*============================================================
Problem: Sudoku Solver
==============================================================
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.
============================================================*/
class Solution {
private:
	int rowValid[9][10];  //rowValid[i][j] represent num j used or not in row i
  	int colValid[9][10];  //colValid[i][j] represent num j used or not in col i
  	int subValid[9][10];  //subValid[i][j] represent num j used or not in subBoard i

  	bool solver(vector<vector<char>>& board, int index) { // 0 <= index <= 80, index is the cell now considering
    	if (index > 80) return true;
    	int row = index / 9, col = index - 9*row;
    	if (board[row][col] != '.')  // this cell is already solved
    		return solver(board, index+1);

    	for (int val='1'; val<='9'; val++) { // try 9 different nums
    		if (isValid(row, col, val-'0')) {
        		board[row][col] = val;
        		fill(row, col, val-'0');
        		if(solver(board, index+1))
        			return true;
        		clear(row, col, val-'0');
      		}
    	}
    	board[row][col] = '.';  // recover the origin state
    	return false;
  	}
  
  	bool isValid(int row, int col, int val) {
    	if (rowValid[row][val] == 0 && colValid[col][val] == 0 && subValid[row/3*3+col/3][val] == 0)
    		return true;
    	return false;
  	}
  
  	// update state
  	void fill(int row, int col, int val) {
  		rowValid[row][val] = 1;
  		colValid[col][val] = 1;
    	subValid[row/3*3+col/3][val] = 1;
  	}
  
  	// recover state
  	void clear(int row, int col, int val) {
    	rowValid[row][val] = 0;
    	colValid[col][val] = 0;
    	subValid[row/3*3+col/3][val] = 0;
  	}

public:
	void solveSudoku(vector<vector<char>>& board) {
    	for(int i = 0; i < 9; i++)
    		for(int j = 0; j < 9; j++)
        		if(board[i][j] != '.')
          			fill(i, j, board[i][j] - '0');  // update Valid information
    solver(board, 0);
  	}
};