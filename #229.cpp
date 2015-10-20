/*============================================================
Problem: Majority Element II
==============================================================
Given an integer array of size n, find all elements that appear 
more than ⌊ n/3 ⌋ times. The algorithm should run in linear 
time and in O(1) space.
============================================================*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n==0) return res;

        int num1, num2, counter1 = 0, counter2 = 0;

        for (int i=0; i<n; i++) {
            if (counter1 == 0 || num1 == nums[i]) {
                num1 = nums[i];
                counter1++;
            }
            else if (counter2 == 0 || num2 == nums[i]) {
                num2 = nums[i];
                counter2++;
            }
            else {
                counter1--;
                counter2--;
            }
        }
        counter1 = 0;
        counter2 = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == num1)
                counter1++;
            else if (nums[i] == num2)
                counter2++;
        }
        if (counter1 > n/3)
            res.push_back(num1);
        if (counter2 > n/3)
            res.push_back(num2);

        return res;
    }
};