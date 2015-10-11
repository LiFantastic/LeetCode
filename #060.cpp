/*============================================================
Problem: Permutation Sequence
==============================================================
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
============================================================*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int tmp=k-1, factorial[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
        vector<char> digits({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
        string res = "";

        for (int i=n-1; i>-1; i--) {
            int index = tmp / factorial[i];
            res += digits[index];
            digits.erase(digits.begin()+index);
            tmp -= index * factorial[i];
        }
        return res;
    }
};