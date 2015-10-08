/*============================================================
Problem: Valid Sudoku
==============================================================
Determine if a Sudoku is valid.

The Sudoku board could be partially filled, where empty cells 
are filled with the character '.'.
============================================================*/
class Solution {
private:
	bool checkValid(int vec[], int val) {
    	if (val < 0) return true;  // '.'
    	if (vec[val]==1) return false;
    	vec[val]=1;
    	return true;
	}
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rowValid[10] = {0};		//check row
    	int colValid[10] = {0};		//check col
    	int subValid[10] = {0};		//check 3*3
    	for (int i=0; i<9; i++) {
      		memset(rowValid, 0, sizeof(rowValid));
      		memset(colValid, 0, sizeof(colValid));
      		memset(subValid, 0, sizeof(subValid));
      		for (int j=0; j<9; j++) {
          		if (!checkValid(rowValid, board[i][j]-'0') ||						// check row[i]
          			!checkValid(colValid, board[j][i]-'0') ||						// check col[j]
            		!checkValid(subValid, board[3*(i/3)+j/3][3*(i%3)+j%3]-'0'))		// check subBoard
             		return false;
      		}
    	}
    	return true;
	}
};