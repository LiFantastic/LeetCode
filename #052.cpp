/*============================================================
Problem: N-Queens II
==============================================================
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total 
number of distinct solutions.
============================================================*/
class Solution {
private:
    int res;
	vector<int> queens;  // queens[i] = j  means there is a queen at position (i, j)
	int n;

    void dfs (int row) {
        if (row == n) {
        	res++;
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
    int totalNQueens(int n) {
        this->n = n;
        queens = vector<int>(n, -1);
        dfs(0);
        return res;
    }
};