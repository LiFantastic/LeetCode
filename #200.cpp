/*============================================================
Problem: Number of Islands
==============================================================
Given a 2d grid map of '1's (land) and '0's (water), count the 
number of islands. An island is surrounded by water and is 
formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded 
by water.

Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
============================================================*/
class Solution {
private:
	int m, n;
    void dfs(vector<vector<char>> &grid, int x, int y) {
    	if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        if(x > 0) dfs(grid, x-1, y);
        if(x < m-1) dfs(grid, x+1, y);
        if(y > 0) dfs(grid, x, y-1);
        if(y < n-1) dfs(grid, x, y+1);
    }	
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        for(int i = 0; i < grid.size(); ++ i)
            for(int j = 0; j < grid[0].size(); ++ j)
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
        return res;
    }
};