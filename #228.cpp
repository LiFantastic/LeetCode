/*============================================================
Problem: Summary Ranges
==============================================================
Given a sorted integer array without duplicates, return the 
summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
============================================================*/
class Solution {
    string format(int begin, int end) {
		char buffer[32];
		if (end == begin)
			sprintf(buffer, "%d", begin);
		else
			sprintf(buffer, "%d->%d", begin, end);
		return string(buffer);
	}
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		if (nums.size()<1) return res;
		int begin, end;
		begin = end = nums[0];
		for (int i=1; i<nums.size(); i++) {
			if (nums[i]==end+1)
				end = nums[i];
			else {
				res.push_back(format(begin, end));
				begin = end = nums[i];
			}
		}
		res.push_back(format(begin, end));
		return res;
	}
};