/*============================================================
Problem: Longest Consecutive Sequence
==============================================================
Given an unsorted array of integers, find the length of the 
longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. 
Return its length: 4.

Your algorithm should run in O(n) complexity.
============================================================*/
class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        unordered_set<int> exist;
        
        for (int i=0; i<num.size(); i++) exist.insert(num[i]);
        int res=0;
        
        for (int i=0; i<num.size(); i++){
            int sum = 1;
            if (exist.find(num[i])!=exist.end()) {
                exist.erase(num[i]);
                int left = num[i]-1;
                while (exist.find(left)!=exist.end()) {
                    sum++;
                    exist.erase(left--);
                }
                int right = num[i]+1;
                while (exist.find(right)!=exist.end()) {
                    sum++;
                    exist.erase(right++);
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};