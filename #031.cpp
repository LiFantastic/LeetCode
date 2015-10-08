/*============================================================
Problem: Next Permutation
==============================================================
Implement next permutation, which rearranges numbers into the 
lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as 
the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column 
and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
============================================================*/
class Solution {
public:
    void nextPermutation(vector<int>& num) {
        int i, j, len=num.size();
        for (i=len-2; i>=0; i--) {
            if (num[i] < num[i+1]) {  // i (i+1 ... end)   things in (...) are in decending order 
                for (j=len-1; j>i-1; j--)  // find the smallest element num[j] in (...) such that num[j]>num[i]
                    if (num[j]>num[i])
                        break;
                swap(num[i],num[j]);  // swap num[i] with a just litter bigger element num[j]
                reverse(num.begin()+i+1,num.end());    // make it ascending in (...)
                return;
            }
        }
        // here means the input is the largest one
        reverse(num.begin(),num.end());
        return;
    }
};