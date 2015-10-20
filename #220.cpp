/*============================================================
Problem: Contains Duplicate III
==============================================================
Given an array of integers, find out whether there are two 
distinct indices i and j in the array such that the difference 
between nums[i] and nums[j] is at most t and the difference 
between i and j is at most k.
============================================================*/
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	set<int> windowK; // set is ordered automatically 
    	for (int i=0; i<nums.size(); i++) {
        	if (i > k) windowK.erase(nums[i-k-1]);  // keep the set contains nums i j at most k
        	auto pos = windowK.lower_bound(nums[i]-t);  // x >= nums[i] - t
        	if (pos != windowK.end() && *pos-nums[i]<=t)  return true;  // x <= nums[i] + t
        windowK.insert(nums[i]);
    }
    return false;
}
};