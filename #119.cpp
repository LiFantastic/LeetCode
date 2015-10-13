/*============================================================
Problem: Pascal's Triangle II
==============================================================
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
Note:
Could you optimize your algorithm to use only O(k) extra space?
============================================================*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre;
        vector<int> cur;
        
        pre.push_back(1);
        if (rowIndex==0) return pre;
            
        for (int i=0; i<rowIndex; i++) {
            cur.clear();
            cur.push_back(1);
            for (int j=0; j<i; j++)
                cur.push_back(pre[j]+pre[j+1]);
            cur.push_back(1);
            pre = cur;
        }
        return cur;
    }
};