/*============================================================
Problem: Median of Two Sorted Arrays
==============================================================
There are two sorted arrays nums1 and nums2 of size m and n 
respectively. Find the median of the two sorted arrays. The 
overall run time complexity should be O(log (m+n)).
============================================================*/
class Solution {
private:
    double findKth(vector<int>& A, int startA, int lenA, vector<int>& B, int startB, int lenB, int k) {
        if (lenA > lenB) // make the first array not longer than the second one
            return findKth(B, startB, lenB, A, startA, lenA, k);
        if (lenA == 0)
            return B[startB+k-1];
        if (k == 1)
            return min(A[startA], B[startB]);
            
        int partA = min(k/2, lenA), partB = k-partA;
        
        if (A[startA+partA-1] < B[startB+partB-1]) // the partA is all range in the smaller k^th elements
            return findKth(A, startA+partA, lenA-partA, B, startB, lenB, k-partA);
        else if (A[startA+partA-1] > B[startB+partB-1]) // the partB is all range in the smaller k^th elements
            return findKth(A, startA, lenA, B, startB+partB, lenB-partB, k-partB);
        else
            return A[startA+partA-1];
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size(), total=m+n;
        if (total % 2 == 1)
            return findKth(nums1, 0, m, nums2, 0, n, total/2+1);
        else
            return (findKth(nums1, 0, m, nums2, 0, n, total/2) + findKth(nums1, 0, m, nums2, 0, n, total/2+1))/2;
    }
};