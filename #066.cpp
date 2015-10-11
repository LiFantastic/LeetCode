/*============================================================
Problem: Plus One
==============================================================
Given a non-negative number represented as an array of digits, 
plus one to the number.

The digits are stored such that the most significant digit is 
at the head of the list.
============================================================*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, n = digits.size();
        for (i=n-1; i>-1; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                break;
            }
            else
                digits[i] = 0;
        }        
        if (i == -1)
        	digits.insert(digits.begin(), 1);
            
        return digits;
    }
};