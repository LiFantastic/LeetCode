/*============================================================
Problem: Contains Duplicate
==============================================================
Given an array of integers, find if the array contains any 
duplicates. Your function should return true if any value 
appears at least twice in the array, and it should return 
false if every element is distinct.
============================================================*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	unordered_set<int> exist;
    	for (auto num : nums) {
        	if (exist.find(num) != exist.end()) return true;
        	else exist.insert(num);
    	}
    	return false;
	}
};