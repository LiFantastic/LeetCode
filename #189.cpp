/*============================================================
Problem: Rotate Array
==============================================================
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] 
is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 
3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
============================================================*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        
        reverse(nums.begin(), nums.begin()+n-k);

        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums.begin()+n-k, nums.begin()+n);
        
        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums.begin(), nums.end());
    }
};