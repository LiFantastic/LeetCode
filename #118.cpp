/*============================================================
Problem: Pascal's Triangle
==============================================================
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
============================================================*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        if (numRows==0) return res;
        
        res.push_back(vector<int>(1,1));        
        for (int i=1; i<numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j=0; j<i-1; j++)
                tmp.push_back(res[i-1][j]+res[i-1][j+1]);
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};